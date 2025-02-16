# EvoOS Kernel

EvoOS is a new operating system designed for both desktop and mobile environments. This repository contains the kernel source code and essential components for building and running EvoOS. EvoOS takes inspiration from existing kernels such as Linux and other modern operating systems.

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
- [Acknowledgements](#acknowledgements)
- [Contact](#contact)

## Introduction

EvoOS is an ambitious project aimed at creating a versatile operating system that can run seamlessly on both desktop and mobile devices. It features a custom kernel, a unique user interface, and optimized performance for various hardware configurations. EvoOS takes reference from Linux and other modern operating systems to incorporate best practices and proven technologies.

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
    git clone https://github.com/VishwamAI/EvoOS.git
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

## Directory Structure

- `src/`: Source code for the kernel and essential components
- `include/`: Header files
- `boot/`: Bootloader code
- `docs/`: Documentation and design notes
- `bin/`: Compiled binaries
- `scripts/`: Build and utility scripts

## Contributing

We welcome contributions from the community! To contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

Please ensure your code adheres to the project's coding standards and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

EvoOS takes inspiration and reference from the following projects:

- [Linux Kernel](https://www.kernel.org)
- [Minix](http://www.minix3.org)
- [FreeBSD](https://www.freebsd.org)
- [NetBSD](https://www.netbsd.org)
- [Xv6](https://pdos.csail.mit.edu/6.828/2020/xv6.html)

We thank the developers and contributors of these projects for their invaluable work and contributions to the open-source community.

## Contact

For questions, suggestions, or feedback, please reach out to us:

- **Kasinadhsarma** - [LinkedIn](https://www.linkedin.com/in/kasinadhsarma/)
- **GitHub Issues** - Open a new issue on this repository

Thank you for contributing to EvoOS!
```

### Notes:

1. Update the repository URL (`https://github.com/VishwamAI/EvoOS.git`) with the actual URL of your GitHub repository.
2. Customize the contact section with relevant links and contact information.
3. Include additional sections or information as needed for your project.
