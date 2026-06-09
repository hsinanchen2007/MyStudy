### 解题思路
循环计算，直到走到第一个元素

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//计算分子分母
void calc(int num1, int* num2, int* output)
{
	output[1] = num2[1];
	output[0] = num2[0] + num1 * num2[1];
	return;
}

int* fraction(int* cont, int contSize, int* returnSize) {
	int* retArr = calloc(sizeof(int), 2);
	*returnSize = 2;

	int i = contSize - 2;
	int num1;
	int num2[2];
	retArr[1] = 1;
	retArr[0] = cont[i + 1];

	while (i>=0)
	{
		num1 = cont[i];
		num2[0] = retArr[1];    //反转分子分母
		num2[1] = retArr[0];
		calc(num1, num2, retArr);
		i--;
	}

	return retArr;
} 
```