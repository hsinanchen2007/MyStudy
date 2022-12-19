### 解题思路
比较笨的方法，先申请两组内存，一组等于输入数组的长度，一组等于数组长度+1.

如果最后需要进位，则用+1长度的数组，如果不用进位，就用digitsSize长度的内存。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int *result = malloc(sizeof(int) * (digitsSize + 1));
	int *result2 = malloc(sizeof(int) * (digitsSize));
	memset(result, 0, sizeof(int) * (digitsSize + 1));
	memset(result2, 0, sizeof(int) * (digitsSize));

	int in = 0;
	int temp = 0;
	temp = 1;

	for (int i = digitsSize - 1; i >= 0; i--) {
		temp = temp + digits[i];
		if (temp >= 10) {
			result[i + 1] = temp - 10;
			temp = 1;
		}else{
			result[i+1] = temp;
			temp = 0;
		}
	}
	if (temp ==1){
		result[0]=1;
		*returnSize = digitsSize+1;
		free(result2);
		return result;
	}else{
		*returnSize = digitsSize;
		memcpy(result2,result+1,digitsSize*sizeof(int));
		free(result);
		return result2;
	}
}

```