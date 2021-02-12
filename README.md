# hex2binary

This small program allows you to convert a text file with hexadecimal values in it into binary files with those values. It's written in pure C99, and should be cross-compatible (except for ``sudo make install``, obviously).

## Example

Type ``3a 44 0a`` into a file called test.txt and run ``h2b test.txt -o test.bin``. If you open up test.bin in a text editor, you should see a smile!

## Compiling and installing

### Prerequisites

- gcc
- make

This program is super small, and a Makefile is probably overkill. But for convenience, I've still provided one. If your distro doesn't have a /usr/local/bin/ folder, open the Makefile and edit the INSTALL_PATH variable to where you want to install h2b. Then just run this:

```bash
git clone https://github.com/SarahIsWeird/hex2binary.git
make
sudo make install
```

## Uninstalling

If you want to remove h2b, you can use this command:

```bash
sudo make uninstall
```

## To-Dos:

[x] Piping support
[ ] Reverse direction support (i. e., hexdump)
[ ] Append support
[ ] Multiple file support
- [ ] Allow reading from multiple files
- [ ] Allow layout files to specify where data should go

## License

Copyright (c) 2021 Sarah Klocke <sarah.klocke@outlook.com>
This work is free. You can redistribute it and/or modify it under the terms of the Do What The Fuck You Want To Public License, Version 2, as published by Sam Hocevar. See the [LICENSE.md](LICENSE.md) file for more details.
