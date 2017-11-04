#include<stdio.h>
#include<time.h>



Int40 *kw26Add(Int40 *p, Int40 *q)
{
	int carry;
	Int40 *num  = (Int40*)malloc(sizeof(Int40));
	if(!num || !p || !q)
		return NULL;
	num->digit = (int*)malloc(sizeof(int)*40);
	if(!num->digit)
		return NULL;
	int i = 0, sum = 0;
	carry = 0;
	for(i = 39; i >= 0; i--)
	{
		sum = p->digit[i] + q->digit[i] + carry;
		
		carry = sum / 16;
		num->digit[i] = sum - (carry * 16);
	}
	return num;
}

Int40 *kw26Destroyer(Int40 *p)
{
	if(!p)
		return NULL;
	if(p->digit)
		free(p->digit);
	free(p);
	return NULL;
}

Int40 *fibKw26(int n, Int40 *first, Int40 *second)
{
	nFib = n;
	if( n == 0)
		return first;
	else if(n == 1)
		return second;
	int i = 0;
	Int40 *tmp;
	for (i = 2; i <= n; i++)
  	{
		tmp = first + second;
		first = kw26Destroyer(first);
		first = second;
		second = tmp;
	}
	return tmp;
}

void kw26Rating(void)
{
	fprintf( stderr, "NID: sh498458;Difficulty: 1.0;Time: 1.5 hr\n");
}

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
			fprintf( stderr, "It need to be a valid HexaDecimal\n");
			num->digit[i] = 0;
		}
	}
	return num;
}

Int40 *loadHWConfigVariable(int doSeed)
{
	seed = doseed;
	srand(time(NULL));
	Int40 *num  = (Int40*)malloc(sizeof(Int40));
	if(!num)
		return NULL;
	num->digit = (int*)malloc(sizeof(int)*40);
	if(!num->digit)
		return NULL;
	int i, j;
	if(seed != 0)
	{
		int random;
		for(i = 0; i < 5; i++)
		{
			random = rand()%10;
			j = 0;
			while(j < i)
			{
				if(num->digit[j] == random)
				{
					j = i;
					i--;
				}
				j++;
			}
			if( j == i)
			{
				num->digits[i] = random;
				num->digits[i + 5] = random;
				num->digits[i + 10] = random;
				num->digits[i + 15] = random;
				num->digits[i + 20] = random;
				num->digits[i + 25] = random;
				num->digits[i + 30] = random;
				num->digits[i + 35] = random;
			}
		}
	}
	else
	{
		for(i = 0; i < 40; i++)
		{
			num->digits[i] = 1;
		}
	}
	return num;
}

Int40 *loadCryptoVariable(char *inputFilename)
{
	cryptoVariableFilename = inputFilename;
	FILE *ifp= fopen(inputFilename);
	if(!ifp)
		return NULL;
	char c;
	int i;
	Int40 *num  = (Int40*)malloc(sizeof(Int40));
	if(!num)
		return NULL;
	num->digit = (int*)malloc(sizeof(int)*40);
	if(!num->digit)
		return NULL;
	for(i = 0; i < 40; i++)
	{
		fprintf(ifp, "%c", &c);
		if(c >= '0' && c  <='9')
			num->digit[i] = c - '0';
		else if(c >= 'A' && c  <='F')
			num->digit[i] = 10 + c - 'A';
		else if(c >= 'f' && c  <='f')
			num->digit[i] = 10 + c - 'a';
		else
		{
			fprintf( stderr, "It need to be a valid HexaDecimal\n");
			num->digit[i] = 0;
		}
	}
}

Int40 *loadPlainText(char *inputFilename)
{
	return parseString("1319df0463129a3245ac0963f78eca0137e42fa0");
}

Int40 *encrypt(Int40 *key, Int40 *inputText)
{
	int i;
	Int40 *num  = (Int40*)malloc(sizeof(Int40));
	if(!num)
		return NULL;
	num->digit = (int*)malloc(sizeof(int)*40);
	if(!num->digit)
		return NULL;
	for(i = 0; i < 40; i++)
	{
		num->digit[i] = key->digit[i] ^ inputText->digit[i];
	}
	return num;
}
