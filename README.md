# TCP Chat Client-Server in C++

This is a simple TCP chat client and server written in C++.

## ⚙️ Build System

Although it's a small project, it uses the **GN build system** along with **Ninja** to generate binaries — just to get hands-on experience with GN. Yes, it's a bit overkill for this, but, just having fun learning! ^^

## 🔧 Commands

### Build

```bash
make build
```

This runs `gn gen out` and then builds the project using `ninja -C out`.

### Clean

```bash
make clean
```

Removes all generated build files (i.e., deletes the `out/` directory).

## 📁 Structure

```bash
.
├── build/                              # GN build-related configuration files
│   ├── BUILDCONFIG.gn                  # Global GN build configuration file
│   ├── BUILD.gn                        # Declares toolchain(s) and global settings
│   └── toolchain/                      # Custom toolchain configuration (if needed)
│       └── BUILD.gn                    # Defines the actual toolchain (e.g., compiler, linker)
├── BUILD.gn                            # Root GN build file; pulls in client and server targets
├── client/                             # Client-side code
│   ├── BUILD.gn                        # GN build file defining the client_main target
│   └── client_main.cpp                 # TCP chat client source code
├── out/                                # Build artifacts (excluded through .gitignore)
├── Makefile                            # Simplifies GN + Ninja commands (build, clean, etc.)
├── README.md                           # Project overview and usage instructions
└── server/                             # Server-side code
    ├── BUILD.gn                        # GN build file defining the server_main target
    └── server_main.cpp                 # TCP chat server source code
```
