# mini-libc

A minimal, freestanding C standard library for Linux on x86-64, built
entirely on top of raw Linux system calls with no external dependencies.

## Overview

This project reimplements a functional subset of the C standard library
from scratch, targeting the x86-64 Linux syscall interface. It can serve
as a drop-in replacement for glibc in constrained or sandboxed environments
where the standard library is unavailable.

## Implemented Features

### String operations (`string.h`)
- `strcpy`, `strncpy`, `strcat`, `strncat`
- `strcmp`, `strncmp`, `strlen`
- `strchr`, `strrchr`, `strstr`, `strrstr`
- `memcpy`, `memmove`, `memset`, `memcmp`

### Memory management (`stdlib.h`, `sys/mman.h`)
- `malloc`, `free`, `calloc`, `realloc`, `reallocarray`
- `mmap`, `mremap`, `munmap` — direct syscall wrappers with errno handling

### File I/O (`unistd.h`, `fcntl.h`, `sys/stat.h`)
- `open`, `close`, `read`, `write`, `lseek`
- `stat`, `fstat`, `truncate`, `ftruncate`

### Other
- `puts` — writes a string to stdout via the `write` syscall
- `sleep`, `nanosleep` — implemented over `__NR_nanosleep`
- `errno` — custom errno propagation from syscall return values

## Implementation Details

- All syscalls are invoked through a thin `syscall()` wrapper defined in
  `syscall.c`, which calls the architecture-specific entry point in
  `include/internal/arch/x86_64/syscall_arch.h`
- Memory allocation is backed by `mmap` with `MAP_PRIVATE | MAP_ANONYMOUS`,
  tracked via an internal linked list (`mem_list`) for `free` and `realloc`
- Error propagation follows the standard libc convention: syscall errors set
  `errno` to the negated return value and return `-1` or `NULL`
- `memmove` is safe for overlapping regions via an intermediate buffer

## Building
```bash
cd libc/
make
```

Requires GCC and `nasm` on an x86-64 Linux machine.

## Architecture
```
minilibc/
├── crt/          # C runtime startup (_start, __libc_start_main)
├── include/      # Header files (string.h, stdlib.h, stdio.h, ...)
├── io/           # open, close, lseek, puts, read_write, truncate
├── mm/           # malloc, free, mmap, mem_list
├── process/      # exit, sleep, nanosleep
├── stat/         # stat, fstat, fstatat
├── string/       # All string and memory functions
└── syscall.c     # Syscall dispatcher
```

## Technologies

C · x86-64 Assembly · Linux System Calls · POSIX