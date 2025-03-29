#include <stdio.h>
#include <string.h>

/*================| FOR CHANGE |================*/
#define OFFSET 3 // The number of lines to skip before starting extraction.
#define LINES  3 // The number of lines to extract after the offset.
/*==============================================*/

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "You have not entered a file name");
        return 1;
    }

    char buffer[1024];
    int line_count = 1;
    int position_in_cycle;
    
    for (int i = 1; i < argc; ++i) {
        FILE *f_from = fopen(argv[i], "r");
        if (f_from == NULL) {
            perror(argv[i]);
            return 1;
        }

        char filename[FILENAME_MAX];
        snprintf(filename, sizeof(filename), "(extracted) %s", argv[i]);

        FILE *f_to = fopen(filename, "w");
        if (f_to == NULL) {
            perror(filename);
            return 1;
        }
        
        while (fgets(buffer, sizeof(buffer), f_from)) {
            position_in_cycle = ((line_count - 1) % (OFFSET + LINES)) + 1;
            if (position_in_cycle > OFFSET && position_in_cycle <= OFFSET + LINES) {
                fprintf(f_to, "%s", buffer);
            }
            line_count++;
        }

        fclose(f_from);
        fclose(f_to);
    }
    return 0;
}   