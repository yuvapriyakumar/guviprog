#include <stdio.h>
#include <string.h>
#define MAXLEN 100
void reverseString(char*, int, int);
void reverseWords(char*, int);
int main()
{
  char string[MAXLEN] = "Kumar Krishan";
  printf("Input String: %s\n", string);
  reverseString(string, 0, strlen(string) - 1);
  reverseWords(string, strlen(string));
  printf("Output String: %s\n", string);
}
void reverseString(char* buffer, int startIndex, int endIndex)
{
  int ch, i, j;
  for (i = startIndex, j = endIndex; i < j; i++, j--)
  {
    ch = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = ch;
  }
}
void reverseWords(char* buffer, int strLength)
{
  if (*buffer == '\0') // check for null
    return;
  int startWord = 0, endWord = 0;
  while (endWord < strLength)
  {
    While (buffer[endWord] != ' ' && buffer[endWord] != '\0')
    {
      endWord++;
    }
    reverseString(buffer, startWord, endWord-1);
    startWord = ++endWord;
  }
}
