### 解题思路
典型的区间更新，然后询问每个数字的值，使用差分可以将O(n)的时间更新转化为O(1)的更新；
题目中需要注意的是，更新区间时是左闭右开，因为要先下车后上车

### 代码

```c
#include <stdio.h>
#define MAX_N 100050
#define MAX(a, b) ((a) > (b) ? (a) : (b))
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
	int *arr = (int *)calloc(1, sizeof(int) * MAX_N);
	int *status = (int *)calloc(1, sizeof(int) * MAX_N);
	int i, left, right, val, maxVal;

	if (tripsSize == 0) {
		return true;
	}

	maxVal = 0;
	for (i = 0; i < tripsSize; i++) {
		left = trips[i][1];
		right = trips[i][2];
		val = trips[i][0];
		arr[left] += val;
		arr[right] -= val;
		maxVal = MAX(maxVal, right);
	}
	for (i = 0; i <= maxVal; i++) {
		status[i + 1] = status[i] + arr[i];
		if (status[i + 1] > capacity) {
			return false;
		}
	}
	return true;
}
```