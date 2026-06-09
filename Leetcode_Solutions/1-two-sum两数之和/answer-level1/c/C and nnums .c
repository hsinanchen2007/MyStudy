#include <stdio.h>
int main(int argc, char const *argv[])
{
	int	target=9,m,n;
	int nums[]={2,7,11,15};
	
	for (m=0;m<4;m++)
	{
		for (n=m+1;n<4;n++)
		{
			if ((nums[m]+nums[n])==target)
			{
				printf("[%d,%d]",m,n);
			}
		}
	}
	
	return 0;
}
                                            ^
___________________________________________ |
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int	target=9,m,n;
	int nums[]={2,7,11,15};
	
	for (m=0;m<4;m++)
		for (n=m+1;n<4;n++)
			if ((nums[m]+nums[n])==target)
				printf("[%d,%d]",m,n);
	return 0;
}

________________________________________________nnums
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int	i,j,l,target,m,n;
	printf("length of array\n");
	scanf("%d",&i);
	int array[i];

	printf("input index\n" );
	for (j=0;j<i;j++)
	scanf("%d",&array[j]);
	
	printf("[");
	for (l=0;l<i;l++)
	printf(" %d ",array[l] );
	printf("]\n");

	printf("input target");
	scanf("%d",&target);

	for (m=0;m<i;m++)
	{
		for (n=m+1;n<i;n++)
		{
			if ((array[m]+array[n])==target)
			{
				printf("[%d,%d]",m,n);
			}
		}
	}
	
	return 0;
}