#include <stdio.h>
#include <string.h>

#define OFFSET  3

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
    snprintf(filename, sizeof(filename), "(1)%s", argv[1]);

    FILE *f_to = fopen(filename, "w");

    char buffer[1024];
    int line = 0;

    while (fgets(buffer, sizeof(buffer), f_from)) {
        if (line == OFFSET) {
            fprintf(f_to, "%s", buffer);
            line = -1;
        }
        line++;
    }

    fclose(f_from);
    fclose(f_to);
    return 0;
}