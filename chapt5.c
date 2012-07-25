#include<stdio.h>

void strcat_modif(char *s, char *t);
void strcpy_modif(char *s, char *t);
int strend(char *s, char *t);
int strlen_modif(char *s);
int strcmp_modif(char *s, char *t);

int main(int argc, char *argv[])
{
	printf("Exercice 5.3\n");
	char s[] = "testadhdhdhhd";
	char *t = "hdhhd";
	strcat_modif(s,t);
	printf("%s\n", s);

	printf("%d\n", strend(s, t));
	return 0;
}

void strcat_modif(char *s, char *t)
{
	while(*s)
	{
		s++;
	}
	strcpy_modif(s, t);

}

void strcpy_modif(char *s, char *t)
{
	while(*s++ = *t++)
		;
	printf("%s\n", s );
}

int strend(char *s, char *t)
{
	int l1 = strlen_modif(s);
	int l2 = strlen_modif(t);

	if (l1 > l2)
	{
		s+= l1 - l2;
		return strcmp_modif(s,t);
	}
	return 0;
}

int strcmp_modif(char *s, char *t)
{
	for(; *s == *t; s++, t++)
	{
		if(*s == '\0') // end of string so SUCCESS
		{
			return 1;
		}
	}
	return *s - *t;
}

int strlen_modif(char *s)
{
	int i;
	for(i=0; *s != '\0'; s++)
	{
		i++;
	}
	return i;
}