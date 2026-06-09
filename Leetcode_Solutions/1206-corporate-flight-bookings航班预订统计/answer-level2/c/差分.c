### 解题思路
差分方法的一些固定套路
1. 差分下标从零开始，前缀和下标从1开始，这样可以方便的更新区间，即
```
		arr[left] += val;
		arr[right + 1] -= val;
```

### 代码

```c
#define MAX_N 20050
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
	int *arr = (int *)calloc(1, sizeof(int) * MAX_N);
	int *ans = (int *)calloc(1, sizeof(int) * MAX_N);
	int *status = (int *)calloc(1, sizeof(int) * MAX_N);
	int left, right, val, i;

	for (i = 0; i < bookingsSize; i++) {
		left = bookings[i][0];
		right = bookings[i][1];
		val = bookings[i][2];
		arr[left] += val;
		arr[right + 1] -= val;
	}

	/* 差分下标从零开始，前缀和下标从1开始 */
	for (i = 0; i <= n + 1; i++) {
		status[i + 1] = status[i] + arr[i];
	}

	/* 答案要求1开始到n，那么对应前缀和2开始到n+1 */
	for (i = 2; i <= n + 1; i++) {
		ans[i - 2] = status[i];
	}
	*returnSize = n;
	return ans;
}
```