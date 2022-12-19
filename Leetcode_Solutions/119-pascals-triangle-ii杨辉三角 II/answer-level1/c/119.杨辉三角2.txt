### 解题思路
时间复杂度O(n^2)。空间复杂度O(n)。
这里采用了对称折半思想，适当降低时间消耗。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex+1;
    int* result = (int*)malloc((rowIndex+1)*sizeof(int));
    int a = 0;
    result[0] = 1;

    for(int i = 1; i <= rowIndex; i++)
    {
		if(i == 1)
			result[1] = 1;
		for(int j = (i/2); j >= 1; j--) //折半，降低时间复杂度
		{
			a = result[j] + result[j-1];
			result[j] = a;
			result[i - j] = a;		//好傻的错误，这里写成了 result[rowIndex - j]
		}
	}
	result[rowIndex] = 1;
	
    return result;
}
```