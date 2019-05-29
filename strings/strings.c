#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int charCount = 0;

    for(int i = 0; s[i]; i++) {
        charCount++;
    }
    // printf("charCounter %d\n", charCount);
    return charCount;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    int length = string_length(s) - 1;
    printf("length: %d\n", length);

    int start = 0;
    printf("start: %d\n", start);

    for (int i = length; i >= 0; i--) {
        printf("-----BEGIN LOOP-----\n");
        printf("i: %d\n", i);
        printf("start: %d\n", start);

        rv[start] = s[i];

        printf("rv[start]: %d\n", rv[start]);
        printf("rv: %s\n", rv);
        
        start++;
        printf("start: %d\n", start);
    }

    rv[start] = 0;
    
    printf("rv: %s\n", rv);
    return rv;
}

// ----- Daren's Test Code ----- 
// char quote1[] = "hello";
// char rv[512];

// int main(void)
// {
//     // string_length(quote1);
//     reverse_string(rv, quote1);

//     return 0;
// }



#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
