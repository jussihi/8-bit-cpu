# A simple 8-bit CPU with a simple assembly instruction set

## Syntax

The intel/NASM syntax is used. There is an example program that will input "Hello World" into the console added.


## Instruction set

All the opcodes are structured:

2 leftmost bits: instruction length, this is the offset to be added to the IP.

6 rightmost bits: instruction (this gives us space for 64 opcodes!)
```
   0   1   2   3   4   5   6   7
 +---+---+---+---+---+---+---+---+
 |Length |Instruction opcode     |
 +---+---+---+---+---+---+---+---+
```

| `Assembly representation`       |  opcode  | Action |
| ------------- | :-----:| ------|
| `DB` |  | Define bytes. This should be in a ro-data section |
| `HLT` | **00000000b** | Halts the CPU |
|**MOV dest, src**|||
| `MOV reg, reg`   |  **11000001b** | Copies the byte from register to another |
| `MOV reg, address`    |   **11000010b** | Copies a byte from address to register |
| `MOV reg, constant`    |   **11000011b** | Moves a constant into register |
| `MOV address, reg`    |   **11000100b** | Copies register byte into memory |
| `MOV address, constant`    |   **11000101b** | Copies register byte into a constant |
|**ADD/SUB dest, src**|||
| `ADD reg, reg` | **11000110b** | Add src register value to dest register value. Modifies only dest! |
| `ADD reg, address` | **11000111b** | Adds byte from address to register | 
| `ADD reg, constant` | **11001000b** | Adds a constant to a register |
| `SUB reg, reg` | **11001001b** | Substracts src register value from dest register value. Modifies only dest! |
| `SUB reg, address` | **11001010b** | Substracts byte from address. Modifies register. |
| `SUB reg, constant` | **11001011b** | Substracts a constant from a register |
|**INC/DEC dest**|||
| `INC reg` | **10001100b** | Increments register value by one |
| `DEC reg` | **10001101b** | Decrements register value by one |
|**MUL/DIV src**|||
| `MUL reg` | **10001110b** | Multiply register A by src register value |
| `MUL address` | **10001111b** | Multiply register A by value in memory |
| `MUL constant` | **10010000b** | Multiply register A by constant |
| `DIV reg` | **10010001b** | Divide register A by src register value |
| `DIV address` | **10010010b** | Divide register A by value in memory |
| `DIV constant` | **10010011b** | Divide register A by constant |
|**Compare instructions**|| |
| `CMP reg, reg` | **11010100b** | Compare registers, set zero flag to true if equal |
| `CMP reg, address` | **11010101b** | Compare register and value in memory, set zero flag to true if equal |
| `CMP reg, constant` | **11010110b** | Compare register and constant, set zero flag to true if equal |
|**Logical instructions dest, src**|||
| `AND reg, reg` | **11010111b** | Stores resulting AND operation in dest register |
| `AND reg, address` | **11011000b** | Stores resulting AND operation in dest register |
| `AND reg, constant` | **11011001b** | Stores resulting AND operation in dest register |
| `OR reg, reg` | **11011010b** | Stores resulting OR operation in dest register |
| `OR reg, address` | **11011011b** | Stores resulting OR operation in dest register |
| `OR reg, constant` | **11011100b** | Stores resulting OR operation in dest register |
| `XOR reg, reg` | **11011101b** | Stores resulting XOR operation in dest register |
| `XOR reg, address` | **11011110b** | Stores resulting XOR operation in dest register |
| `XOR reg, constant` | **11011111b** | Stores resulting XOR operation in dest register |
|**Shift instructions dest, count**|||
| `SHL reg, reg` | **11100000b** | Shifts dest register left by *count* |
| `SHL reg, address` | **11100001b** | Shifts dest register bits left by *count* |
| `SHL reg, constant` | **11100010b** | Shifts dest register left by *count* |
| `SHR reg, reg` | **11100011b** | Shifts dest register right by *count* |
| `SHR reg, address` | **11100100b** | Shifts dest register right by *count* |
| `SHR reg, constant` | **11100101b** | Shifts dest register right by *count* |
|**Jumps**|||
| `JMP address` | **10100110b** | Change instruction pointer (**IP**) to point to the *address* |
| `JC addr`, `JB addr`, `JNAE addr` | **10100111b** | Jump if: (Carry=TRUE) **meaning** lower (<) **OR** if not more or equal (! >=) |
| `JNC addr`, `JNB addr`, `JAE addr` | **10101000b** | Jump if: (Carry=FALSE) **meaning** not lower (! <) **OR** if more or equal (>=) |
| `JZ addr`, `JE addr` | **10101001b** | Jump if: (Zero=TRUE) **meaning** equal (==) |
| `JNZ addr`, `JNE addr` | **10101010b** | Jump if: (Zero=FALSE) **meaning** not equal (!=) |
| `JA addr`, `JNBE addr` | **10101011b** | Jump if: (Carry=TRUE || Zero=TRUE) **meaning** higher (>) **OR** not less or equal (! <=) |
| `JNA addr`, `JBE addr` | **10101100b** | Jump if: (Carry=TRUE && Zero=TRUE) **meaning** lower or equal (<=) **OR** not higher (! >) |
|**Other**|||
| `CALL address` | **10101101b** | Change instruction pointer (**IP**) to point to the *address*. Push the next instruction to stack. |
| `RET` | **10101110b** | Return from a function. |
| `PUSH register` | **10101111b** | Push register value to stack. |
| `PUSH address` | **10110000b** | Push value from memory to stack. |
| `PUSH constant` | **10110001b** | Push constant to stack. |
| `POP reg` | **10110010b** | Pop a value from stack to register. |