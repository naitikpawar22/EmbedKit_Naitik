# EmbedKit_Naitik

## Embedded C Ring Buffer (Circular Buffer) Implementation

Author: Naitik Pawar

---

# Module Description

- ringbuf.c - Implements a fixed-size circular ring buffer (FIFO queue) for uint8_t data with full/empty detection and optimized wrap-around logic.

---

# Project Overview

This project implements a Ring Buffer (Circular Buffer) in Embedded C using standard C99.

A ring buffer is commonly used in embedded systems for:
- UART communication
- Serial data handling
- Producer-consumer systems
- Interrupt Service Routine (ISR) buffering
- Real-time firmware applications

The implementation demonstrates:
- FIFO (First In First Out) operation
- Buffer full protection
- Buffer empty protection
- Circular wrap-around handling
- Efficient embedded-style memory management

---

# Features

- Fixed-size circular buffer (8 bytes)
- FIFO data handling
- Buffer full detection
- Buffer empty detection
- Safe read/write operations
- Byte count tracking
- Bitwise wrap-around optimization
- Embedded-oriented coding practices
- Zero compiler warnings and errors

---

# Technologies Used

- Language: C (C99)
- Compiler: GCC
- Libraries:
  - stdio.h
  - stdint.h
  - stdlib.h

---

# Project Structure

```text
EmbedKit_Naitik/
│
├── ringbuf.c
├── README.md
```

---

# Ring Buffer Concept

The ring buffer uses:
- `head` → next write position
- `tail` → next read position

When the buffer reaches the end of the array, indices wrap back to the beginning, forming a circular structure.

---

# Bonus Optimization

This implementation replaces modulo (`%`) wrap-around with bitwise AND optimization:

```c
index = (index + 1) & (BUFFER_SIZE - 1);
```

Advantages:
- Faster than modulo operation
- Avoids expensive division instructions
- Useful on MCUs without hardware dividers

Note:
This optimization works only when `BUFFER_SIZE` is a power of 2.

---

# Build Instructions

Compile the program using GCC:

```bash
gcc -Wall -std=c99 ringbuf.c -o ringbuf
```

This command generates:

```text
ringbuf.exe
```

---

# How to Run (Windows CMD)

## Step 1: Open Command Prompt

Press:

```text
Windows + R
```

Type:

```text
cmd
```

Press Enter.

---

## Step 2: Navigate to Project Folder

Example:

```bash
cd Desktop\EmbedKit_Naitik
```

---

## Step 3: Compile the Program

Run:

```bash
gcc -Wall -std=c99 ringbuf.c -o ringbuf
```

---

## Step 4: Execute the Program

Run:

```bash
ringbuf.exe
```

or

```bash
.\ringbuf.exe
```

---

# Run Instructions (Linux/macOS)

Compile:

```bash
gcc -Wall -std=c99 ringbuf.c -o ringbuf
```

Run:

```bash
./ringbuf
```

---

# Program Demonstration

The program demonstrates:

1. Writing 8 bytes into the buffer
2. Detecting full buffer condition
3. Preventing overwrite on full buffer
4. Reading bytes from the buffer
5. Reusing freed buffer positions
6. Detecting empty buffer condition
7. Preventing invalid reads from empty buffer

---

# Expected Output

```text
====================================
 Ring Buffer Demonstration Program
====================================

[WRITE] 0x41 -> OK   (count=1)
[WRITE] 0x42 -> OK   (count=2)
[WRITE] 0x43 -> OK   (count=3)
[WRITE] 0x44 -> OK   (count=4)
[WRITE] 0x45 -> OK   (count=5)
[WRITE] 0x46 -> OK   (count=6)
[WRITE] 0x47 -> OK   (count=7)
[WRITE] 0x48 -> OK   (count=8) FULL

[WRITE] 0x99 -> FAIL (buffer full)

[READ ] -> 0x41 (count=7)
[READ ] -> 0x42 (count=6)
[READ ] -> 0x43 (count=5)

[WRITE] 0x49 -> OK   (count=6)
[WRITE] 0x4A -> OK   (count=7)
[WRITE] 0x4B -> OK   (count=8)

[READ ] -> 0x44 (count=7)
[READ ] -> 0x45 (count=6)
[READ ] -> 0x46 (count=5)
[READ ] -> 0x47 (count=4)
[READ ] -> 0x48 (count=3)
[READ ] -> 0x49 (count=2)
[READ ] -> 0x4A (count=1)
[READ ] -> 0x4B (count=0)

Buffer is now EMPTY

[READ ] (empty) -> FAIL (buffer empty)
```

---

# Code Quality

This project follows embedded software development practices:

- Fixed-width integer types (`uint8_t`)
- No magic numbers
- Modular function design
- Defensive programming
- Clean output formatting
- Optimized wrap-around logic
- Readable naming conventions

---

# Author

Naitik Pawar

Computer Engineering Student  
Savitribai Phule Pune University (SPPU)

---

# Assignment

Embedded Developer Fresher Assessment  
Embed Square Solutions Pvt. Ltd.
