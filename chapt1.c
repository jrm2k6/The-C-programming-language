#include<stdio.h>

int is_alpha(char c);
float temperature_conversion(int far);
void print_longer_than_eighty();
void remove_trailing_blanks_and_tab();


int main(int argc, char *argv[])
{   
   /* printf("------Ex 1.1 ----\n");
    printf("hello wor\jld\n");
    printf("------Ex 1.2 ----\n");

    float far,celsius;
    int lower,upper,step;

    step = 20;
  
    celsius = 0;
    printf("Celsius - Far\n");
    while(celsius <= 300)
    {
        far = 9.0/5.0 * (celsius+32.0);
        printf("%f \t %f \n", celsius, far);
        celsius+=20;
    }
    
    
    printf("------Ex 1.8 ----\n");
    char output[1000];
    char c;
    int i= 0;
    int blank_detected = 1; // 1 = false;
    
    while((c = getchar()) != EOF)
    {
      if((c == ' ' && blank_detected == 1))
      {
	  printf("\'%c\' : blank\n", c);
	  output[i] = c;
	  blank_detected = 0; // true
	  i++;
      }
      else if (c != ' ')
      {
 	printf("\'%c\' : letter\n", c);
	output[i] = c;
	i++;
	if(blank_detected == 0) blank_detected = 1;
      }
      
    }
    
    printf("output : %s\n", output);
    
    
    printf("------Ex 1.10 ----\n");
    char output[1000];
    char c;
    int i= 0;
    
    while((c = getchar()) != EOF)
    {
      if(c == '\t')
      {
	putchar('\\');
	putchar('t');
      }
      else if (c == '\b') 
      {
	putchar('\\');
	putchar('b');
      }
      else if (c == '\\') 
      {
	putchar('\\');
	putchar('\\');
      }
      else 
      {
	putchar(c);
      }
      
      
    }
    printf("------Ex 1.12 ----\n");
      char c;
      
      while((c = getchar()) != EOF)
      {
	if(c == ' ')
	{
	  putchar('\n');
	}
	else 
	{
	  putchar(c);
	}
      }
    
   
   printf("------Ex 1.13 ----\n");
   // vertical histogram not done
      int lengths[10];
      char c;
      int current_length = 0;
      int i;
      int j;
      
      for(i=0; i< 10; i++) lengths[i] = 0;
      
      while((c = getchar()) != EOF)
      {
	if(c == ' ' || c == '\n')
	{
	  lengths[current_length] += 1;
	  current_length = 0;
	}
	else 
	{
	  current_length++;
	}
      }
    
    printf("Word length repartition :\n");
    for(i=0; i < 10; i++)
    {
      printf("length %3d  :", i+1);
      for(j=0; j<lengths[i]; j++) printf("--");
      printf("\n");
    }
    
    printf("\n");
    
   
   printf("------Ex 1.14 ----\n");
   // not done with histogram
      int occurrences[26];
      char c;
      int i;
      int j;
      
      for(i=0; i< 26; i++) occurrences[i] = 0;
      
      while((c = getchar()) != EOF)
      {
	if(is_alpha(c) == 0)
	{
	  occurrences[c - 'a'] += 1;
	}
      }
    
    printf("Word length repartition :\n");
    for(i=0; i < 26; i++)
    {
      printf("frequencies %c  %d \n", i + 'a', occurrences[i] );
    }
    
    printf("\n"); 
    
    
   printf("------Ex 1.15 ----\n");
   int i;
   for(i=0; i<=300; i+=20)
   {
     //printf("%d\n", i);
     printf("far : %3d - celsius %f \n", i, temperature_conversion(i));
   }
   
   printf("------Ex 1.17 ----\n");
   print_longer_than_eighty();
   
   printf("------Ex 1.18 ----\n");
   remove_trailing_blanks_and_tab();
   */
   
   printf("------Ex 1.19 ----\n");
   
   remove_trailing_blanks_and_tab();
   
   return 0;
}



int is_alpha(char c)
{
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 0;
  else return 1;
}



float temperature_conversion(int far)
{
    return 5.0/9.0 * (far - 32.0);
}

void print_longer_than_eighty()
{
  char line[1000];
  int length=0;
  int i,j;
  char c;
  
  i=0;
  while((c = getchar()) != EOF)
  {
      line[i] = c;
      i++;
      length++;
      if(c == '\n')
      {
	line[i] = '\0';
	if(length > 80)
	{
	  printf("Longer than 80 : %s", line);
	  i=0;
	  length=0;
	}
      }
  }
}


void remove_trailing_blanks_and_tab()
{
  char line[1000];
  char trailing[1000];
  int blanks=1;
  int i;
  int position = 0;
  char c;
  
  i=0;
  while((c = getchar()) != EOF)
  {
      if(c == ' ' || c == '\t')
      {
	if(blanks == 1) 
	{
	  blanks = 0;
	  position = i;
	}
	line[i] = c;
      }
      else if (c != '\n')
      {
	if(blanks == 0) blanks = 1;
	line[i] = c;
      }
      
      i++;
      
      if(c == '\n')
      {
	if(blanks == 0) 
	{
	  int j;
	  for(j=0; j<position; j++)
	  {
	   trailing[j] = line[j];
	  }
	  trailing[position] = '\0';
	  printf("trailing blanks : %s-\n", trailing);
	}
	else 
	{
	  line[i-1] = '\0';
	  printf("no trailing blanks : %s-\n", line);
	}
	i=0;
      }
  }
}

void reverse(s)
{
  char reversed[1000];
  int i;
  int length = 0;
  
  i=0;
  // determine length of the word
  while(s[i] != '\0')
  {
    length+=1;
    i++;
  }
  
  for(i=length; i>=0; i--)
  {
    reversed[i-length] = s[i];
  }
  
  printf("reversed is : %s", reversed);
}




