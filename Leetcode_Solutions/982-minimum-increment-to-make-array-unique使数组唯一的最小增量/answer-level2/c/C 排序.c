### 解题思路
	排完序后如果后面一个数小于等于前面一个数则赋值为前一个数+1，增量为改变的差值。

### 代码

```c
int cmp(const void *a, const void *b) {
	return *(int*)a > *(int*)b;
}
int minIncrementForUnique(int* A, int ASize) {
	if (A == NULL || ASize <= 1) return 0;
	int move = 0;
	int prev = 0;
	// sort
	qsort(A, ASize, sizeof(int), cmp);
	for (int i = 1; i < ASize; ++i) {
		if (A[i] <= A[i - 1]) {
			prev = A[i];
			A[i] = A[i - 1] + 1;
			move += A[i] - prev;
		}
	}
	return move;
}
```