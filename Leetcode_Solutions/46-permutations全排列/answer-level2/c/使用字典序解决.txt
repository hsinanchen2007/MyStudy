还记得之前我们做过的一道题目：[求下一个字典序](https://leetcode-cn.com/problems/next-permutation/)。其实求一个数组的全排列可以等价的求这个数组元素的所有的字典序，话不多说，直接上代码。

```c
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

void quickSortR(int* arr, int begin, int end) {
	if (end - begin > 0) {
		int left = begin;
		int right = end;
		int pivot = *(arr + begin);
		while (left < right) {
			while (left < right && *(arr + right) >= pivot) {
				right--;
			}
			while (left < right && *(arr + left) <= pivot) {
				left++;
			}	
			swap(arr, left, right);
		}
		swap(arr, begin, left);
		quickSortR(arr, begin, left - 1);
		quickSortR(arr, left + 1, end);
	}
}

void quickSort(int* arr, int size) {
	quickSortR(arr, 0, size - 1);
}

void addToRes(int* nums, int numsSize, int** res, int* returnSize) {
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		*(arr + i) = *(nums + i);
	}
	*(res + *returnSize) = arr;
	*returnSize = *returnSize + 1;
}

/**
* 生成所有的字典序列
*/
void generateAllLexicographically(int* nums, int numsSize, int** res, int* returnSize) {
	addToRes(nums, numsSize, res, returnSize);
	while (1) {
		int k = -1;
		// 找到 k,使得 nums[k] < nums[k+1]
		for (int i = 0; i < numsSize - 1; i++) {
			if (*(nums + i) < *(nums + i + 1)) {
				k = i;
			}
		}
		if (k == -1) {  // 说明此时的数组已经全部为逆序，字典序生成结束
			break;
		}
		else { // 说明 nums 还有下一个更大的字典序
			int min = *(nums + k + 1);
			int pos = k + 1;
			// 从 k+1 往后面找，找到一个数 a,使得 a[k] < a < a[k+1]
			for (int i = k + 1; i < numsSize; i++) {
				int temp = *(nums + i);
				if (temp > * (nums + k) && temp <= min) {
					min = temp;
					pos = i;
				}
			}
			// 交换 k 和 pos 位置
			swap(nums, k, pos);
			// 将 k+1 ~ numsSize-1 之间的元素进行反转
			int mid = (k + 1 + numsSize) / 2;
			for (int i = k + 1; i < mid; i++) {
				int _i = numsSize - i + k;
				swap(nums, i, _i);
			}
			addToRes(nums, numsSize, res, returnSize);
		}
	}
}

/**
* 使用字典序求解
*/
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int total = factorial(numsSize);
	*returnSize = total;
	*(returnColumnSizes) = (int*)malloc(sizeof(int) * total);
	for (int i = 0; i < total; i++) {
		*(*(returnColumnSizes)+i) = numsSize;
	}
	int** res = (int**)malloc(sizeof(int*) * total);
	quickSort(nums, numsSize);
	int size = 0;
	generateAllLexicographically(nums, numsSize, res, &size);
	return res;
}
```

设数组的大小为`n`,则 n 个不同的元素，共有 n! 个排列，每次计算下一个字典顺序，需要`O(n)`,因此总得时间复杂度为`O(n*n!)`,但是不会消耗额外的空间