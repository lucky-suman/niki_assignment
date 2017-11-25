#include <iostream>

#define MODULUS 1000000007

using namespace std;

void multiply(long long int FIB[2][2], long long int MUL[2][2]);
 
void power(long long int FIB[2][2], long long int n);

long long int fib(long long int n)
{
  long long int FIB[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(FIB, n+1);
  return (FIB[0][0])%MODULUS;
}


void power(long long int FIB[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int MUL[2][2] = {{1,1},{1,0}};
 
  power(FIB, n/2);
  multiply(FIB, FIB);
 
  if (n%2 != 0)
     multiply(FIB, MUL);
}

void multiply(long long int FIB[2][2], long long int MUL[2][2])
{
  long long int x =  ((FIB[0][0]*MUL[0][0])%MODULUS + (FIB[0][1]*MUL[1][0])%MODULUS)%MODULUS;
  long long int y =  ((FIB[0][0]*MUL[0][1])%MODULUS + (FIB[0][1]*MUL[1][1])%MODULUS)%MODULUS;
  long long int z =  ((FIB[1][0]*MUL[0][0])%MODULUS + (FIB[1][1]*MUL[1][0])%MODULUS)%MODULUS;
  long long int w =  ((FIB[1][0]*MUL[0][1])%MODULUS + (FIB[1][1]*MUL[1][1])%MODULUS)%MODULUS;
 
  FIB[0][0] = x;
  FIB[0][1] = y;
  FIB[1][0] = z;
  FIB[1][1] = w;
}

int main()
{
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		cout << fib(n) << endl;
	}
	return 0;
}
