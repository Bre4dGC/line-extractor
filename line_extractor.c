#include <stdio.h>
#include <string.h>

/* FOR CHANGE */
#define OFFSET 3  // Offset for extraction
#define LINES  3  // Number of lines for extract

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *f_from = fopen(argv[1], "r");
    if (f_from == NULL) {
        perror(argv[1]);
        return 1;
    }

    char filename[FILENAME_MAX];
    snprintf(filename, sizeof(filename), "(edited) %s", argv[1]);

    FILE *f_to = fopen(filename, "w");

    char buffer[1024];
    int line_count = 1;

    while (fgets(buffer, sizeof(buffer), f_from)) {
        int position_in_cycle = ((line_count - 1) % (OFFSET + LINES)) + 1;
        if (position_in_cycle > OFFSET && position_in_cycle <= OFFSET + LINES) {
            fprintf(f_to, "%s", buffer);
        }
        line_count++;
    }

    fclose(f_from);
    fclose(f_to);
    return 0;
}   