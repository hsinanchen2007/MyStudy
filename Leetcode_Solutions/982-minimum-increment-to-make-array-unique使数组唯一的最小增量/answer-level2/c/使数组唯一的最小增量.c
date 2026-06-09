### 解题思路
排序后遍历数组，若当前元素小于或等于上一个元素，当前元素加至上一个元素加一，count更新

### 代码

```c
int CMP_INT(const void *_a,const void *_b) {
	return *(int*)_a - *(int*)_b;
}

int minIncrementForUnique(int* A, int ASize) {
	qsort(A, ASize, sizeof(int), CMP_INT);
	int count = 0;
	for (int i = 1; i < ASize; i++) {
		if (A[i] <= A[i - 1]) {
			count+=A[i-1]-A[i]+1;
			A[i] = A[i-1]+1;
		}
	}
	return count;
}

```