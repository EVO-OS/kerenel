# kerenel

EvoOS is a new operating system designed for both desktop and mobile environments. This repository contains the kernel source code and essential components for building and running EvoOS.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building EvoOS](#building-evoos)
  - [Running EvoOS](#running-evoos)
- [Directory Structure](#directory-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

EvoOS is an ambitious project aimed at creating a versatile operating system that can run seamlessly on both desktop and mobile devices. It features a custom kernel, a unique user interface, and optimized performance for various hardware configurations.

## Features

- Custom kernel with modular design
- Support for both desktop and mobile environments
- Advanced memory management and process scheduling
- Custom filesystem for efficient storage management
- Basic device drivers for essential hardware components
- Command-line shell for interacting with the system
- Graphical user interface for desktop and mobile

## Getting Started

### Prerequisites

To build and run EvoOS, you need the following tools and libraries installed on your development machine:

- GCC cross-compiler (e.g., `i386-elf-gcc`)
- GNU Make
- QEMU (for emulation)
- Git

### Building EvoOS

1. **Clone the Repository:**
    ```bash
    git clone https://github.com/EVO-OS/kerenel.git
    cd EvoOS
    ```

2. **Set Up the Cross-Compiler:**
    Ensure you have a cross-compiler installed. If not, you can set it up using the following commands:
    ```bash
    sudo apt-get install gcc gcc-multilib build-essential
    wget https://ftp.gnu.org/gnu/binutils/binutils-2.34.tar.gz
    tar -xzf binutils-2.34.tar.gz
    cd binutils-2.34
    ./configure --target=i386-elf --disable-nls --disable-werror
    make
    sudo make install
    ```

3. **Build the Kernel:**
    ```bash
    make
    ```
### Running EvoOS

You can run EvoOS using QEMU for testing and development:

```bash
qemu-system-i386 -kernel bin/kernel.bin
```
### Directory Structure
src/: Source code for the kernel and essential components
include/: Header files
boot/: Bootloader code
docs/: Documentation and design notes
bin/: Compiled binaries
scripts/: Build and utility scripts
Contributing
We welcome contributions from the community! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Make your changes and commit them (git commit -am 'Add new feature').
Push to the branch (git push origin feature-branch).
Create a new Pull Request.
Please ensure your code adheres to the project's coding standards and includes appropriate tests.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
For questions, suggestions, or feedback, please reach out to us:

Kasinadhsarma - LinkedIn
GitHub Issues - Open a new issue on this repository
Thank you for contributing to EvoOS!

### Running EvoOS

You can run EvoOS using QEMU for testing and development:

```bash
qemu-system-i386 -kernel bin/kernel.bin
