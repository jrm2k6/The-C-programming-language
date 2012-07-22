#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void htoi(char s[]);
int hl_to_int(char c);

int main(int argc, char* argv[])
{
  printf("------_Exercise 2.3 ---\n");
  printf("-- htoi --\n");
  htoi("0X2b6");
  htoi("0x2b6F56");
  
 return 0; 
}



void htoi(char s[])
{
  // 0x1221 0X2221
  int length = strlen(s);
  int i;
  char lc;
  int value;
  int result = 0;
  int ind = 0;
  
  for(i = length-1; i > 1; --i)
   {
       lc = tolower(s[i]);
       value = (lc >= 'a' && lc <= 'z')? hl_to_int(lc) : lc - '0';
       //printf("%c - %d-  ind %d\n", s[i], value, ind);
       result += value * pow(16,ind);
       ind++;
   }
  
  printf("%s : %d\n",s, result);
  
}

int hl_to_int(char c)
{
 int result;
 switch(c)
 {
   case 'a': 
      result = 10;
      break;
   case 'b': 
      result = 11;
      break;
   case 'c': 
      result = 12;
      break;
   case 'd': 
      result = 13;
      break;
   case 'e': 
      result = 14;
      break;
   case 'f': 
      result = 15;
      break;
   default: 
      result = 0;
      break;
 }
 
 return result;
  
}