
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
	int *B;
	B=(int*)malloc(ASize * sizeof(int));
	int i,j;
	j=0;
	for(i = 0;i < ASize; i++)
		if( A[i]%2 == 0 )
		{
		    B[j] = A[i];
			j+=2;
		}
	j=1;
	for(i = 0;i < ASize; i++)
		if( A[i]%2 == 1 )
		{
			B[j] = A[i];
			j+=2;
		}
	*returnSize = ASize;
	return B;
}
```