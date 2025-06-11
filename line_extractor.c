#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*================| FOR CHANGE |================*/
#define OFFSET 3         // The number of lines to skip before starting extraction.
#define LINES 1          // The number of lines to extract after the offset.
#define MERGE_LINES true // If true, the strings will be written as a single line separated by a space.
/*==============================================*/

int main(int argc, char const *argv[])
{
        /* Verify that the user has specified a filename. */
        if (argc < 2)
        {
                fprintf(stderr, "You have not entered a file name");
                return 1;
        }

        char buffer[1024];     // Buffer to hold each line read from the file.
        int line_count = 1;    // Line counter to keep track of the current line number.
        int position_in_cycle; // Position in the cycle of lines to determine if we are within the extraction area.

        /* Loop through each file specified in the command line arguments. */
        for (int i = 1; i < argc; ++i)
        {
                FILE *f_from = fopen(argv[i], "r");
                if (f_from == NULL)
                {
                        perror(argv[i]);
                        return 1;
                }

                char filename[FILENAME_MAX];                     // Buffer to hold the new filename.
                const char *last_slash = strrchr(argv[i], '\\'); // Find the last backslash in the path.

                if (last_slash)
                {
                        // Extract the directory path and original filename.
                        size_t dir_length = last_slash - argv[i] + 1;
                        strncpy(filename, argv[i], dir_length);
                        filename[dir_length] = '\0'; // Null-terminate the directory path.

                        // Append "(extracted) " and the original filename.
                        snprintf(filename + dir_length, sizeof(filename) - dir_length, "(extracted) %s", last_slash + 1);
                }
                else
                {
                        // If no backslash is found, assume the file is in the current directory.
                        snprintf(filename, sizeof(filename), "(extracted) %s", argv[i]);
                }

                FILE *f_to = fopen(filename, "w");
                if (f_to == NULL)
                {
                        perror(filename);
                        fclose(f_from);
                        return 1;
                }

                /* Reads each line from the original file and writes the specified lines to the new file. */
                while (fgets(buffer, sizeof(buffer), f_from))
                {
                        position_in_cycle = (line_count % (OFFSET + LINES)) + 1; // Calculate the position in the line cycle.

                        /* Check if the current line is within the range of lines to be extracted. */
                        if (position_in_cycle > OFFSET && position_in_cycle <= OFFSET + LINES)
                        {
                                if (MERGE_LINES)
                                {
                                        // Delete the newline character, if there is one
                                        buffer[strcspn(buffer, "\n")] = '\0';
                                        fprintf(f_to, "%s ", buffer);
                                }
                                else
                                {
                                        fprintf(f_to, "%s", buffer);
                                }
                        }
                        line_count++;
                }

                if (MERGE_LINES)
                {
                        fprintf(f_to, "\n"); // Add a newline at the end of the merged line.
                }

                line_count = 1; // Reset the line count for the next file.

                fclose(f_from);
                fclose(f_to);
        }
        return 0;
}
