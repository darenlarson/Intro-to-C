#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/

int string_length(char *s)
{
    int length = 0;
    while (*s != '\0')
    {
        length++;
        s = s + 1;
    }
    return length;
}

void string_copy(char *x, char *y)
{
    // Calculate the length of string y
    int length = string_length(y);
    printf("length: %d\n", length);

    // Map string y over to string x
    for (int i = 0; i <= length; i++)
    {
        x[i] = y[i];
        printf("%s\n", x);
    }
    printf("%s\n", x);
}


/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    // Calc the length of string str
    int length = string_length(str);
    printf("length: %d\n", length);


    // Initialize a pointer we will return
    char *first_char = str;
    // printf("%c\n", first_char[0]);

    // Loop through string str looking for character c
    for (int i = 0; i <= length; i++)
    {
        printf("%c\n", first_char[i]);
        if (first_char[i] == c)
        {
            first_char = &first_char[i];
            printf("first_char: %p\n", first_char);
            printf("first_char value: %c\n", *first_char);
            return first_char;
        }
    }
    return NULL;
    printf("first_char: %p\n", first_char);
}


/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    // Calc the length of string haystack
    int length_haystack = string_length(haystack);
    printf("haystack length: %d\n", length_haystack);

    // Calc the length of string needle
    int length_needle = string_length(needle);
    printf("needle length: %d\n", length_needle);

    // Loop through string haystack looking for string needle
    for (int i = 0; i <= length_haystack; i++)
    {
        printf("----- START FIRST FOR LOOP -----\n");
        printf("haystack[i] %c\n", haystack[i]);
        printf("needle[0] %c\n", needle[0]);

        // Check to see if current character in haystack string == 1st character in needle string
        if (haystack[i] == needle[0])
        {
            // Set a boolean to true to indicate matching
            int match = 1;
            printf("match: %d\n", match);

            // loop over needle string to see if other characters are matching
            for (int j = 0; j < length_needle; j++)
            {
                printf("----- START SECOND FOR LOOP -----\n");
                printf("haystack[i+j] %c\n", haystack[i+j]);
                printf("needle[j] %c\n", needle[j]);

                // if the i+jth char in haystand doesn't equal jth char in needle, reset match to 0
                if (haystack[i+j] != needle[j])
                {
                    match = 0;
                }
            }
            if (match == 1)
            {
                char *str_pointer = &haystack[i];
                printf("str_pointer address: %p\n", str_pointer);
                printf("first_char value: %c\n", *str_pointer);
                return str_pointer;
            }
        }
    }
    return NULL;
}

// int main(void)
// {
    // ----- Test for string_copy -----
    // char buffer[1024];
    // string_copy(buffer, "Hello");
    // printf("buffer: %s\n", buffer);

    // ----- Test for find_char -----
    // char *string_pointer = "LambdaSchool";
    // find_char(string_pointer, 'b');

    // ----- Test for find_string -----
    // char *haystack = "a needla needle";
    // find_string(haystack, "needle");

    // return 0;
// }



#ifndef TESTING
int main(void)
{
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
