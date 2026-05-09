# EmbedKit_Naitik

## Embedded C Ring Buffer (Circular Buffer) Implementation

This project implements a fixed-size Ring Buffer (Circular FIFO Queue) in Embedded C using standard C99.  
The assignment demonstrates buffer management techniques commonly used in embedded firmware systems such as UART communication, interrupt-driven data transfer, and producer-consumer architectures.

---

# Features

- Fixed-size circular buffer (8 bytes)
- FIFO (First In First Out) operation
- Buffer full detection
- Buffer empty detection
- Safe read/write operations
- Count tracking
- Efficient wrap-around using bitwise AND optimization
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
