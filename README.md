# Line Extractor

This is a simple C program that extracts a specific line from a text file and saves it to a new file.

## Description

The program reads an input text file and writes the 3rd line (by default) to a new output file. The output filename is prefixed with "(edited)" to distinguish it from the original file.

## Features

- Extracts a specific line from a text file (3rd line by default)
- Creates a new file with the extracted line
- Handles file opening errors gracefully
- Simple command-line interface

## Usage

1. Compile the program:
   ```bash
   gcc -o line_extractor line_extractor.c
   ```

2. Run the program with an input file:
   ```bash
   ./line_extractor file.txt
   ```

3. The program will create a new file named "(edited)file.txt" containing the 3rd line from the original file.

## Configuration

You can change which line is extracted by modifying the `OFFSET` constant in the source code:
```c
#define OFFSET 3  // Change this value to extract a different line
```

## Requirements

- C compiler (gcc, clang, etc.)
- Standard C library

## Notes

- If the input file has fewer lines than the specified offset, the output file will be empty
- The program handles basic error cases (missing file argument, unreadable files)
