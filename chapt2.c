#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

void htoi(char s[]);
int hl_to_int(char c);
void squeeze(char s1[], char s2[]);
int any(char s1[], char s2[]);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
void lower(char w[]);


int main(int argc, char* argv[])
{
  // printf("------_Exercise 2.3 ---\n");
  // printf("-- htoi --\n");
  // htoi("0X2b6");
  // htoi("0x2b6F56");

  // printf("------_Exercise 2.4 ---\n");
  // printf("-- squeeze(s1,s2) --\n");
  // squeeze("chien aquatoque", "velo");

  // printf("------_Exercise 2.5 ---\n");
  // printf("-- any(s1,s2) --\n");
  // int position = any("chien aquatoque", "velo");
  // printf("first char occurs at position : %d\n", position);

  printf("------_Exercise 2.10 ---\n");
  printf("-- lower --\n");
  lower("Ceci Est UN TesT");
  
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




void squeeze(char s1[], char s2[])
{
  char result[1000];
  int i,j,k,in_s2 = 1;

  k = 0;
  for(i=0; i< strlen(s1); i++)
  {
    if(in_s2 == 0) in_s2 = 1;
    for(j=0; j< strlen(s2); j++)
    {
      if(s1[i] != ' ' && s1[i] == s2[j]) in_s2 = 0;
    }

    if(in_s2 == 1) 
    {
      result[k] = s1[i];
      k++;
    }
  }
  result[k] = '\0';
  printf("s1 - s2 : %s\n", result);
}

int any(char s1[], char s2[])
{
  char result[1000];
  int i,j = 1;

  for(i=0; i< strlen(s1); i++)
  {
    for(j=0; j< strlen(s2); j++)
    {
      if(s1[i] != ' ' && s1[i] == s2[j]) return i;
    }
  }
  return -1;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{

}

unsigned invert(unsigned x, int p, int n)
{

}

unsigned rightrot(unsigned x, int n)
{

}

void lower(char w[])
{
  char result[100];
  char nc;
  int i;
  for(i=0; i < strlen(w); i++)
  {
    nc = (w[i] >= 'A' && w[i] <= 'Z')? w[i] - 'A' + 'a' : w[i];
    result[i] = nc;
  }
  printf("%s\n", result);
}



