### 解题思路
把偶数存到新的数组中，然后去存奇数就好了

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	int  *B;
	B=(int *) malloc ( ASize * sizeof( int ) );
	int i,j = 0;
	for(i = 0;i < ASize; i++)
		if( A[i]%2 == 0 )
		    B[j++] = A[i];
	for(i = 0;i < ASize; i++)
		if( A[i]%2 == 1 )
			B[j++] = A[i];
	*returnSize = ASize;
	return B;
}
```