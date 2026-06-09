### 解题思路
此处撰写解题思路
从最后一位开始，循环判断当前位是否为9，如果是9，则赋值为0，否则加1，循环结束后，判断是否全部进位，如果是，将新数组（只有最高位为0）返回。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i;
	//处理全部为9的情况
    int* newdigits = (int *)malloc(sizeof(int) * (digitsSize+1));
    for (i = 0; i < digitsSize + 1; i++)
			newdigits[i] = 0;
	for (i = digitsSize - 1; i >= 0; i--) {
		if (digits[i] == 9) {
			digits[i] = 0;
		}
		else {
			digits[i] += 1;
            *returnSize = digitsSize;
			return digits;
		}
	}
	if (i == -1) {
		newdigits[0] = 1;
	}
	*returnSize = digitsSize + 1;
	return newdigits;
}
```