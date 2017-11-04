#include<stdio.h>


typedef struct Int40
{
  // a dynamically allocated array to hold a 40
  // digit integer, stored in reverse order
  int *digits;
} Int40;

typedef struct kw26RatingStruct{
  char *NID; //pointer to a malloc'ed buffer for the NID
  float degreeOfDifficulty; //1.0 for super easy to 5.0 for insanity++
  float duration; // Hours spent writing, reading,
                  // designing & building the code
} kw26RatingStruct;

char *cryptoVariableFilename; // for the filename

int seed;//to seed the RNG or not

int nFib; //control the number of Fibonacci numbers to calculate

// F[0] is loaded with the cryptovariable
Int40 *cryptoVariable; // 40 digits used to start the F[x]

// F[1] is loaded with the hwConfigvariable
Int40 *hwConfigVariable; // 40 digits of psuedo or real
                         // randomness to start the F[x]
// Functional Prototypes

Int40 *kw26Add(Int40 *p, Int40 *q);

Int40 *kw26Destroyer(Int40 *p);

Int40 *fibKw26(int n, Int40 *first, Int40 *second);

void kw26Rating(void);

Int40 *parseString(char *str)
{
	int size = 0;
	char *ptr;
	ptr = str;
	while(ptr)
	{
		size++;
		ptr++;
	}
	if(size == 0)
		return NULL;
	else if(size > 40)
		fprintf( stderr, "It String is more than 40 Digits\n");
	else if(size < 40)
		fprintf( stderr, "It String is less than 40 Digits\n");
	Int40 *num  = (Int40*)malloc(sizeof(Int40));
	if(!num)
		return NULL;
	num->digit = (int*)malloc(sizeof(int)*40);
	if(!num->digit)
		return NULL;
	int i = 0;
	for( i = 0; i < 40 - size; i++)
	{
		num->digit[i] = 0;
	}
	int j = 0;
	for( j = 0; i < 40; i++, j++)
	{
		if(str[j] >= '0' && str[j]  <='9')
			num->digit[i] = str[j] - '0';
		else if(str[j] >= 'A' && str[j]  <='F')
			num->digit[i] = 10 + str[j] - 'A';
		else if(str[j] >= 'f' && str[j]  <='f')
			num->digit[i] = 10 + str[j] - 'a';
		else
		{
			fprintf( stderr, "It String is less than 40 Digits\n");
			num->digit[i] = 0;
		}
	}
	return num;
}

Int40 *loadHWConfigVariable(int doSeed);

Int40 *loadCryptoVariable(char *inputFilename);

Int40 *loadPlainText(char *inputFilename);

Int40 *encrypt(Int40 *key, Int40 *inputText);
#endif

