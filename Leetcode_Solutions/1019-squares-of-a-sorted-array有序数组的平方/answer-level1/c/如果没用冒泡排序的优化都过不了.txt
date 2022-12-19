

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortedSquares(int* A, int ASize, int* returnSize)
{
	int *B=(int *)malloc(ASize * sizeof(int)),i,j,t,n,k=ASize-1,flag;
	*returnSize=ASize;
	for(i=0;i<ASize;i++)
	{
		if(A[i]<0)
			A[i]=-A[i];
	}
	for(i=1;i<ASize;i++)
    {
		for(j=0;j<k;j++)
        {
		    if(A[j]>A[j+1])
			{
				t=A[j];
			    A[j]=A[j+1];
				A[j+1]=t;
                n=j;
                flag=false;
			}
        }
        k=n;
        if(flag)
        break;
    }
    for(i=0;i<ASize;i++)
	{
		B[i]=A[i]*A[i];
	} 
	return B;
}
```