### 解题思路
排序后输出前K个数

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int cmp_int(const void* _a, const void* _b) {
	return *(int*)_a - *(int*)_b;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
	int* ret = (int*)malloc(sizeof(int)*k);
	qsort(arr, arrSize, sizeof(int), cmp_int);
	memcpy(ret, arr, sizeof(int)*k);
	*returnSize = k;
	return ret;
}
```