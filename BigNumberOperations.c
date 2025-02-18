#include <stdio.h>
#include <stdlib.h>

int printer(int s, int x[s], int revPer)
{
	if(revPer == 0)
	{
		for(int i = 0; i < s; i++)
		{
			printf("%d", x[i]);
		}
	}
	else
	{
		for(;s--;)
		{
			printf("%d", x[s]);
		}
	}
	printf("\n");
}

int isTwoDigit(int n)
{
	return n >= 10? 1 : 0;
}

int** borrowFunc(int s, int x[s], int i)
{
	int t = i;
	for(;i--;)
	{
		if(x[i] != 0)
		{
			x[i] -= 1;
			break;
		}
		else if(i != t)
		{
			x[i] = 9;
		}
	}
	x[t] += 10;
}

int** checkFunc(int s, int x[s], int y, int i)
{
	return x[i] >= y? 0 : borrowFunc(s, (int *)x, i);
}

int** initialization(int n, int x[n])
{
	for(;n--;){x[n] = 0;}
}

int** Add(int s, int s2, int x[s], int y[s2])
{
	int s1 = s;
	int carryOver = 0;
	int newArr[s1];
	while(1)
	{
		if(s1 == 0 && s2 < 0)
		{
			newArr[s1] = x[s1] + carryOver;
			break;
		}
		else if(s1 == 0)
		{
			newArr[s1] = x[s1] + y[s2] + carryOver;
			break;
		}
		if(s2 < 0)
		{
			newArr[s1] = (x[s1] + carryOver) % 10;
			s1--, carryOver = isTwoDigit(x[s1] + carryOver);
			continue;
		}
		if(isTwoDigit(x[s1] + y[s2] + carryOver) == 1)
		{
			newArr[s1] = ((x[s1] + y[s2]) % 10) + carryOver;
		}
		else
		{
			newArr[s1] = x[s1] + y[s2] + carryOver;
		}
		carryOver = isTwoDigit(x[s1] + y[s2] + carryOver);
		s1--, s2--;
	}
	printer(s + 1, newArr, 0);
}

int** Subtract(int s, int s2, int x[s], int y[s2])
{
	int s1 = s;
	int newArr[s1];
	while(1)
	{
		if(s1 == 0 && s2 < 0)
		{
			newArr[s1] = x[s1];
			break;
		}
		if(s1 == 0 && s2 == 0)
		{
			newArr[s1] = x[s1] - y[s2];
			break;
		}
		if(s1 > 0)
		{
			checkFunc(s, (int *)x,  y[s2], s1);
			newArr[s1] = x[s1] - y[s2];
		}
		s1--, s2--;
	}
	printer(s + 1, newArr, 0);
}

int** Multiplication(int s, int s3, int x[s], int y[s3])
{
	int s1 = s, s2 = s3 + 1, nArrS = s + s3, newArr[s1 + s3], a = 0;
	initialization(s1 + s3, (int *)newArr);
	for(; s2--;)
  {
		for(int j = s1 + 1, carry = 0; j--;)
	  {
			newArr[nArrS - (j + s2)] += ((y[s2] * x[j]) + carry);
			if(isTwoDigit(newArr[nArrS - (j + s2)]) == 1 && j != 0)
			{
				carry = newArr[nArrS - (j + s2)] / 10, newArr[nArrS - (j + s2)] %= 10;
			}
			else
			{
				carry = 0;
			}
	  }
  }
	printer((s + s3) + 1, newArr, 1);
}

int main()
{
	int* inp1;
  int* inp2;
  char c;
  int j = 1, i = 0, op = 0, s1 = 0, s2 = 0, q;

	inp1 = (int*)calloc(j, sizeof(int));
  printf("Enter your first number: \n");
  while(c != '\n')
  {
    c = getc(stdin);
    inp1 = (int*)realloc(inp1, j * sizeof(int));
    inp1[i] = c - 48;
    i++, j++, s1++;
  }

  j = 1, i = 0, c = '0';

  inp2 = (int*)calloc(j, sizeof(int));
  printf("Enter your second number: \n");
  while(c != '\n')
  {
    c = getc(stdin);
    inp2 = (int*)realloc(inp2, j * sizeof(int));
    inp2[i] = c - 48;
    i++, j++, s2++;
  }

	s1 -= 2, s2 -= 2;

  printf("\nSelect the operation: \n  1 - Addition\n  2 - Subtraction\n  3 - Multiplication\n  4 - Division\n\n");
  scanf("%d", &op);
  switch(op)
  {
    case 1 :
				if(s1 >= s2)
				{
					Add(s1, s2, (int *)inp1, (int *)inp2);
				}
				else if(s2 > s1)
				{
					Add(s2, s1, (int *)inp2, (int *)inp1);
				}
      	break;
    case 2 :
				if(s1 > s2)
				{
					Subtract(s1, s2, (int *)inp1, (int *)inp2);
				}
				else if(s1 == s2)
				{
					for (q = 0; q < s1; q++)
					{
						if(inp1[q] != inp2[q])
						{
							inp1[q] > inp2[q]? Subtract(s1, s2, (int *)inp1, (int *)inp2) : Subtract(s2, s1, (int *)inp2, (int *)inp1);
							break;
						}
					}
					if(q == s1)
					{
						printf("0\n");
					}
				}
				else if(s2 > s1)
				{
					Subtract(s2, s1, (int *)inp2, (int *)inp1);
				}
				break;
    case 3 :
				if(s1 > s2)
				{
					Multiplication(s1, s2, (int *)inp1, (int *)inp2);
				}
				else if(s1 == s2)
				{
					for (q = 0; q < s1; q++)
					{
						if(inp1[q] != inp2[q])
						{
							inp1[q] > inp2[q]? Multiplication(s1, s2, (int *)inp1, (int *)inp2) : Multiplication(s2, s1, (int *)inp2, (int *)inp1);
							break;
						}
					}
				}
				else if(s2 > s1)
				{
					Multiplication(s2, s1, (int *)inp2, (int *)inp1);
				}
     		break;
    case 4 :
     		printf("Access denied");
     		break;
    default :
     		printf("Invalid Option\n");
   }

	free(inp1);
  free(inp2);
}
