/*
 * K&R Exercise 1-24.
 *
 * Check C file for rudimentary syntax errors.
 * Unmatched parentheses, brackets and braces
 * Quotes, both single and double, escape sequences, and comments.
 *
 * TODO: add check for missing semi-colons (';')
 */

/*
NOTE:
Waaruit bestaat de delen van de data die ik ga parsen?
- preprocessor delen (de includes en defines)
- comments
- definitions
- declarations
- parentheses
- braces
- brackets
- strings
- character notation (single quotes)
- funtion declarations
- function opstellen, definieren, aanroepen
- variable opstellen, definieren, aanroepen
- Structs, Unions, enums etc. etc.
- etc....... Basically, a lot

Wat wil ik checken:
- Unmatched parentheses;
- Unmatched brackets;
- Unmatched braces;
- Unmatched quotes (single and double);
- Comments (// and / ** /)
- Error in escape sequences ?How/what/why?
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int getState (int state, char c);

int main(int argc, char const *argv[])
{
    /* Definitions: */
    FILE * fsrc;
    
    int i, 
        openbrace = 0, 
        closedbrace = 0,
        openbracket = 0,
        closedbracket = 0,
        openparenth = 0,
        closedparenth = 0, 
        single_quote = 0,
        double_quote = 0, 
        state;

    char c;

    /* Open file: */
    fsrc = fopen("test_124.c", "r");

    /* Loop through file, read char */
    for (i = 0; (c = getc(fsrc)) != EOF; ++i)
    {
        if (c == '{')
        {
            ++openbrace;
        }
        else if (c == '}')
        {
            ++closedbrace;
        }
        else if (c == '[')
        {
            ++openbracket;
        }
        else if (c == ']')
        {
            ++closedbracket;
        }
        else if (c == '(')
        {
            ++openparenth;
        }
        else if (c == ')')
        {
            ++closedparenth;
        }
        else if (c == '\'')
        {
            ++single_quote;
        }
        else if (c == '\"')
        {
            ++double_quote;
        }
    }

    /* Print number of check symbols: */
    printf("openbrace = %d\n", openbrace);
    printf("closedbrace = %d\n", closedbrace);
    printf("openbracket = %d\n", openbracket );
    printf("closedbracket = %d\n", closedbracket);
    printf("openparenth = %d\n", openparenth);
    printf("closedparenth = %d\n", closedparenth);

    printf("\nsingle quote = %d\n", single_quote);
    printf("double quote = %d\n\n", double_quote);

    
    /* Check if there are mismatched of the check symbols: */
    if (openbrace != closedbrace)
    {
        if (openbrace > closedbrace)
        {
            printf("There is/are %d closedbrace(s) missing \n", 
                openbrace - closedbrace);
        }
        else if (closedbrace > openbrace)
        {
            printf("There is/are %d openbrace(s) missing \n", 
                closedbrace - openbrace);
        }
    }

    if (openbracket != closedbracket)
    {
        if (openbracket > closedbracket)
        {
            printf("There is/are %d closedbracket(s) missing \n", 
                openbracket - closedbracket);
        }
        else if (closedbracket > openbracket)
        {
            printf("There is/are %d openbracket(s) missing \n", 
                closedbracket - openbracket);
        }
    }

    if (openparenth != closedparenth)
    {
        if (openparenth > closedparenth)
        {
            printf("There is/are %d closedparenth(s) missing \n", 
                openparenth - closedparenth);
        }
        else if (closedparenth > openparenth)
        {
            printf("There is/are %d openparenth(s) missing \n", 
                closedparenth - openparenth);
        }
    }

    char * test = "Hello, " "world";
    printf("test = %s\n", test);


    /*for (i = 0; (c = getc(fsrc)) != EOF; ++i)
    {
        if (c == '{')
        {
            if (openbrace > 0)
            {
                // There is an unmatched brace;
                // Unclear as to which one is missing a brace,
                // when braces are nested;
                printf("Unmatched brace detected at line IDK\n");
                openbrace = 0;
            }
            ++openbrace;
        }
        else if (c == '}')
        {
            ++closedbrace;
            --openbrace;
        }
    }*/

    return 0;
}

int getState (int state, char c)
{

}
