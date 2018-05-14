#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

int strcompare(char *a, char *b) {
int i = 0;
   while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] > b[i]) 
           return 1;
        if (a[i] < b[i])
           return -1;
        if (a[i] == '\0' && b[i] != '\0')
           return -1;
        if (a[i] != '\0' && b[i] == '\0')
           return 1;
        if (a[i] == '\0' && b[i] == '\0')
           return 0;
        i++;
}  return 0;
 };

int main()
{
  char Strings[NUM][LEN];
  int i;
  int j;
  char temp;

  printf("Please enter %d strings, one per line:\n", NUM);

  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is $
     long does not exceed the bounds imposed by the string's length.  Note that$
     newline and NULL characters will be included in LEN.
  */
  for (i = 0; i < NUM; i++) {
        fgets(Strings[i], LEN, stdin);
}

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings. */

  for (i = 0; i < NUM; i++) {
        printf("%s", Strings[i]);
 }
 int sorted = 0;

  while(!sorted) {
        sorted = 1;
        for (i = 0; i < NUM -1; i++) { /*comparing string sub 0 and string sub 1*/
           int comparisonResult = strcompare(Strings[i], Strings[i+1]);  /*return 1, 0, or -1*/
           if (comparisonResult > 0) {
              sorted = 0;
              for (j = 0; j < LEN; j++) {
                temp = Strings[i][j];
                Strings[i][j] = Strings[i+1][j];
                Strings[i+1][j] = temp;
              }
           }
        }
}

puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/prin$
     etc. for printing each string.
  */
  for (i = 0; i < NUM; i++) {
        printf("%s", Strings[i]);
} return 0;
}

