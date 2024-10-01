/*
 * Solomon Dawit
    Test file with prewritten examples to help construct the strings we wish to test against
    Test code I wrote covers different edges such as empty strings and all ascii symbols
    I test in between as well, making sure spaces don't count as duplicate and uppercase are distinct from lowercase
 */

#include <stdio.h>    // printf
#include <stdbool.h>  // to define a boolean type and true, false
#include <string.h>   // strcpy  to copy a string
#include <assert.h>


// declaration of function from hasUniqueChars.c
bool hasUniqueChars(char * inputStr);


int main() {

  // ------------------------------------------------------------
  // Examples of declaring string constants
  /* Example 1 */
  char string1[] = "A string declared as an array.\n";

  /* Example 2 */
  char *string2 = "A string declared as a pointer.\n";

  /* Example 3 */
  char string3[128];   // can copy in up to 127 characters
                       // chose 128 because it is a multiple of 8 bytes
  strcpy(string3, "A string constant copied in.\n");

  // You can uncomment these to see how the strings were initialized above.
  // Then you can comment these out again once you see that the 
  // strings were created correctly
  // printf ("%s", string1);
  // printf ("%s", string2);
  // printf ("%s", string3);

  // -------------------------------------------------------------
  // Thorough and exhaustive tests of hasUniqueChars()  
  bool ok;    // holds the result of hasUniqueChars(); used in asserts
  
  // Test 1: a test case that should return false because characters are duplicated
  strcpy(string3, "This should fail (l and s and i and h)");
  ok = hasUniqueChars(string3);
  assert(!(ok));
  
  // Test 2: This should be true and not fail, but won't work until you
  // complete the hasUniqueChars() function
  strcpy(string3, "abcdefghij");
  ok = hasUniqueChars(string3);
  assert(ok);
  
  // Test 3:  This should be true and not fail, because there are no duplicates
  strcpy(string3, "a b c d e f");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 4: This should be true and not fail, becase spaces don't count as duplicates
  strcpy(string3, "         ");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 5:  This should be true and not fail, because there are no duplicates
  strcpy(string3, "0123456789");
  ok = hasUniqueChars(string3);
  assert(ok);

  // Test 6: This should be false and fail, because there are duplicates
  strcpy(string3, "This and that and the third");
  ok = hasUniqueChars(string3);
  assert(!(ok));

 // Test 6: This should be false and fail, because there are duplicates
  strcpy(string3, "1111111111 and 111111111111 or 2222222222");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  // Test 7: This should be true and not fail, because there are no duplicates in all the ascii 
  // symbol values  
  strcpy(string3, "!@#$^&*()""0123456789:;");
  ok = hasUniqueChars(string3);
  assert(ok);

  //Test 8: This should be true and not fail, there are no duplicates between A_Z and a_z
  strcpy(string3, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  ok = hasUniqueChars(string3);
  assert(ok);

  //Test 9: This should fail, there are duplicates
  strcpy(string3, "abcDEFGHIJKLMNOPQRSTUVWXYZabcdefGHijklmnopqrstuvwxyz");
  ok = hasUniqueChars(string3);
  assert(!(ok));

  //Test 10: This should pass, there are no duplicates because spaces don't count
  strcpy(string3, "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z");
  ok = hasUniqueChars(string3);
  assert(ok);

  // NOTE: if you add a \n to any tests, this should cause the
  //       exit failure given. Keep this test last so you can check 
  //       that others pass or fail as you expect them to.
  // strcpy(string3, "a b cc\n");
  // ok = hasUniqueChars(string3);
  // other examples that should fail that you can place in strings
  // are \0 or \t or \r
  // See problem description for more details about escape sequences
  
  return 0;
}