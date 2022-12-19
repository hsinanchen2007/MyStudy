### 解题思路
此处撰写解题思路

### 代码

```c
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

// 计算 n!
int factorial(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		int r = 1;
		for (int i = n; i >= 1; i--) {
			r *= i;
		}
		return r;
	}
}

/**
* 交换数组两个角标的元素
*/
void swap(int* arr, int idx1, int idx2) {
	int temp = *(arr + idx1);
	*(arr + idx1) = *(arr + idx2);
	*(arr + idx2) = temp;
}

/**
* 递归的生成数组 nums 的全排列
* @param nums 原数组
* @param numsSize 原数组大小
* @param res 存放最终所有的结果
* @size res size 的地址
* @param 当前第 nth 个元素
*/
void doPermutes(int* nums, int numsSize, int** res, int* size, int nth) {
	if (nth == numsSize) { // 元素全部取完
		int* arr = (int*)malloc(sizeof(int) * numsSize);
		for (int i = 0; i < numsSize; i++) {
			*(arr + i) = *(nums + i);
		}
		*(res + *size) = arr;
		*size = *size + 1;
	}
	else {
		for (int i = nth; i < numsSize; i++) {
			// 交换位置，相当于 nth 分别取(nth ~ numsSize-1) 的元素，然后递归的解决下一个位置
			swap(nums, nth, i);
			doPermutes(nums, numsSize, res, size, nth + 1);
			// 最后要交换回来
			swap(nums, nth, i);
		}
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int total = factorial(numsSize);
	*returnSize = total;
	*(returnColumnSizes) = (int*)malloc(sizeof(int) * total);
	for (int i = 0; i < total; i++) {
		*(*(returnColumnSizes)+i) = numsSize;
	}
	int** res = (int**)malloc(sizeof(int*) * total);
	int size = 0;
	doPermutes(nums, numsSize, res, &size, 0);
	return res;
}
```