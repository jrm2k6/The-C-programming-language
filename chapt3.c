#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int binsearch_modified(int x, int v[], int n);
void escape(char t[]);
void expand(char s1[]);
void itob(int n, int b);
void reverse(char from[]);
void atoi_modified(int n, char s[], int width);
void reverse_bis(char s[]);

int main(int argc, char* argv[])
{
  // printf("------_Exercise 3.1 ---\n");
  // int atest[] = {1,2,4,5,6,8,9};
  // printf("%d\n", binsearch_modified(6, atest, 7));

  // printf("------_Exercise 3.2 ---\n");
  // printf("------ escape(s) ---\n");
  // escape("bonjour les \n   amis  \tca va");

  //printf("---- Exercise 3.3 ---\n");
  //printf("expand(s1,s2)\n");
  //expand("chA-Z9ma-xen");

  printf("----- Exercise 3.5 ---\n");
  printf("itob(n,s,b)\n");
  int i;
  itob(12, 2);

  printf("----- Exercise 3.6 ---\n");
  printf("atoi_modified(int n, char s[], int width)\n");
  char s[100];
  atoi_modified(124, s, 5);
  
 return 0; 
}

int binsearch_modified(int x, int v[], int n)
{
  int low, high, mid;
  low =0;
  high = n-1;

  while(low < high)
  {
    mid = (low+high)/2;
    if(x <= v[mid]) high = mid;
    else low = mid + 1;
  }

  return (x == v[low]? low : -1);
}

void escape(char t[])
{
  char result[100];
  int i=0;
  int j=0;
  
  while(t[i])
  { 
    switch(t[i])
    {
      case '\t':
        result[j++] = '\\';
        result[j] = 't';
        break;
      case '\n':
        result[j++] = '\\';
        result[j] = 'n';
        break;
      default:
        result[j] = t[i];
        break;
    }
    j++;
    i++;
    result[j] = '\0';
  }
  printf("%s\n", result);
}

void expand(char s1[])
{
  char result[100];
  char f,l;
  int i, j, ir;
  
  ir = 0;
  for(i=0; i< strlen(s1); i++)
  {
    if(s1[i] == '-' && (i == 0 || i == strlen(s1))) 
    {
      result[ir++] = s1[i];
    }
    else if (s1[i] == '-')
    {
      f = s1[i-1];
      l = s1[i+1];
      if(f < l)
      {
        for(j = 1; j < l - f; j++)
        {
          result[ir++] = f + j;
        }
      }
    }
    else
    {
      result[ir++] = s1[i];
    }
  }
  result[ir++] = '\0';
  printf("%s\n", result);
}

void itob(int n, int b)
{
  char c;
  char result[100];
  int i = 0;
  while(n != 0)
  {
    c = n % b;
    n /= b;
    result[i++] = '0' + c;
  }
  result[i++] = '\0';
  reverse(result);
}

void reverse(char from[])
{
  char result[100];
  int i,j = 0;
  for(i=strlen(from)-1; i >= 0 ; i--, j++)
  {
    result[j] = from[i];
  }
  result[j++] = '\0';
  printf("%s\n", result);
}

void atoi_modified(int n, char s[], int width)
{
  int i, sign;
    
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    
    while (i < width )
        s[i++] = '0';
    
    s[i] = '\0';
    reverse_bis(s);
    printf("%s\n", s);

}

void reverse_bis(char s[]) 
{
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) 
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}


