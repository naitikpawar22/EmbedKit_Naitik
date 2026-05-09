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
- Full and empty state detection
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
