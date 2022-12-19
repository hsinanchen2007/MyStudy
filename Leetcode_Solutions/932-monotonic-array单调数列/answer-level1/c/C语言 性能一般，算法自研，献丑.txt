### 解题思路
先把原数组求差值，变成ASize-1大小的差值数组
然后求差值数组的最大和最小值
如果最大和最小值都在0的同侧，即要么都大于等于0，要么都小于等于0，那么就是单调数列

### 代码

```c
bool isMonotonic(int* A, int ASize){
	int i;
	int max = INT_MIN;
	int min = INT_MAX;
	if (ASize <= 1) {
		return true;
	}
	for (i = 0; i < ASize - 1; i++) {
		A[i] = A[i] - A[i + 1];
	}
	for (i = 0; i < ASize - 1; i++) {
		if (A[i] > max) {
			max = A[i];
		}
		if (A[i] < min) {
			min = A[i];
		}
	}
	return (min * max) >= 0;
}
```