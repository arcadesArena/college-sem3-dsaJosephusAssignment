#include <stdio.h>

int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int n,k;
	printf("The number of prisoners: ");
	scanf("%d",&n);
	printf("The number of prisoners to be skipped: ");
	scanf("%d",&k);	
	printf("The safe place is %d", josephus(n, k));
	return 0;
}
