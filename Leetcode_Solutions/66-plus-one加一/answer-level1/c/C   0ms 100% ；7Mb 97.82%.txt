### 解题思路

一.如果最后一位不是9，那么最后一位加一
二.如果最后一位是9，分为两种情况
1.全是9，数组size+1；数组第一位变为1，其余全为0
2.不全是9，从后往前找到第一个不是9的数，+1

### 代码

```c
#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *nums = (int *)calloc(digitsSize + 1, sizeof(int));
	if (digits[digitsSize - 1] != 9) {
		*returnSize = digitsSize;
		digits[digitsSize - 1] += 1;
		return digits;
	}
	if (digits[digitsSize - 1] == 9) {
		nums[digitsSize - 1] = 0;
		int i = digitsSize - 2;
		for (; i >= 0; i--) {
			if (digits[i] == 9) {
				nums[i] = 0;
			}
			else {
				nums[i] = digits[i] + 1;
				break;
			}
		}
		if (i == -1) {
			nums[0] = 1;
			*returnSize = digitsSize + 1;
			nums[digitsSize] = 0;
		}
		else {
			*returnSize = digitsSize;
			for (int j = 0; j < i; j++) {
				nums[j] = digits[j];
			}
		}
	}
	return nums;
}
```