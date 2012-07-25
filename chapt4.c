#include<ctype.h>
#include<stdio.h>
#include<string.h>

double atof(char s[]);
int strindex(char s[], char t[]);

int main(int argc, char *argv[])
{
	printf("Exercice 4.1\n");
	char *s = "montfiergolfiere";
	char *t = "fier";
	printf("%s %s %d\n", s, t, strindex(s,t));
	printf("Exercice 4.2\n");
	printf("%f\n", atof("13.45"));
	return 0;
}

double atof(char s[])
{
	double val, power, val_exponent;
	int i, sign, exponent, sign_exponent, j;

	for(i=0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-')? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}

	if (s[i] == '.')
		i++;

	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	exponent = (lower(s[i]) == 'e')? 1 : 0;
	if(exponent == 1)
		i++;
	sign_exponent = (s[i] == '-')? -1 : 1;
	
	if(sign_exponent == 1)
		i++;

	for(j = i+1; isdigit(s[j]); j++)
	{
		val_exponent = 10.0 * val_exponent + (s[j] - '0');
	}

	val_exponent = (sign_exponent == -1)? val_exponent = 1 / val_exponent : val_exponent;
	return (sign * val / power) * val_exponent;
}

int strindex(char s[], char t[])
{
	int i, j, k, rightmost;
	rightmost = -1;
	for(i=0; s[i] != '\0'; i++)
	{
		for(j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if(k > 0 && t[k] == '\0')
			rightmost = i;
	}
	return rightmost;
}