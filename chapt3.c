#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int binsearch_modified(int x, int v[], int n);
void escape(char t[]);

int main(int argc, char* argv[])
{
  // printf("------_Exercise 3.1 ---\n");
  // int atest[] = {1,2,4,5,6,8,9};
  // printf("%d\n", binsearch_modified(6, atest, 7));

  printf("------_Exercise 3.2 ---\n");
  printf("------ escape(s) ---\n");
  escape("bonjour les \n   amis  \tca va");
  
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

