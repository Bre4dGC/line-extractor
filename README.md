# Line Extractor

This is a simple C program that extracts specific lines from a text file based on an offset and a number of lines to extract. The extracted lines are saved to a new file.

## Description

The program reads one or more input text files and writes the extracted lines to new output files. Each output filename is prefixed with "(extracted)" to distinguish it from the original file.

## Features

- Extracts lines from a text file based on a configurable offset and number of lines.
- Supports merging extracted lines into a single line separated by spaces.
- Processes multiple files in a single run.
- Creates new files with the extracted lines.

---

## Usage

1. Compile the program:
   ```bash
   gcc -o line_extractor line_extractor.c
   ```

2. Run the program with one or more input files:
   ```bash
   ./line_extractor file1.txt file2.txt
   ```

3. The program will create new files named "(extracted) file1.txt", "(extracted) file2.txt", etc., containing the extracted lines.

---

## Configuration

You can modify the constants `OFFSET`, `LINES`, and `MERGE_LINES` in the source code to adjust the behavior:
```c
#define OFFSET       3        // The number of lines to skip before starting extraction.
#define LINES        1        // The number of lines to extract after the offset.
#define MERGE_LINES  true     // If true, the extracted lines will be merged into a single line separated by spaces.
```

---

## Requirements

- C compiler (gcc, clang, etc.)
- Standard C library

## Notes

- If the input file has fewer lines than the specified offset, the output file will be empty.
- The program handles basic error cases, such as missing file arguments or unreadable files.
- The program processes each file independently, creating separate output files for each input file.
- When `MERGE_LINES` is enabled, a newline character is added at the end of the merged line.