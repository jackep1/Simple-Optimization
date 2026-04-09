#include <stdio.h>
#include <stdbool.h>
#include "search_bracket.h"


int main(int argc, char *argv[])
{
    // Check for the right number of arguments for making points
    if (argc < 4)
    {
        printf("INVALID%d\n", argc);
        return 1;
    }
    int num_inputs = argc - 1;
    int num_brackets = num_inputs - 2;

    search_bracket* brackets = malloc(num_brackets * sizeof(search_bracket));
    for (int i = 0; i < num_brackets; i++)
    {
        // Create the bracket, ensure f(c) < f(a or b)
        brackets[i] = store_bracket(3, argv + 1 + i);
        if (!fc_strict_min(brackets[i]) || !acb_ordered(brackets[i]))
        {
            printf("INVALID\n");
        }

        // Use c as best guess for minimum, print it
        printf("VALID %.1f %.1f\n", brackets[i].c.x, brackets[i].c.y);
    }

    return 0;
}