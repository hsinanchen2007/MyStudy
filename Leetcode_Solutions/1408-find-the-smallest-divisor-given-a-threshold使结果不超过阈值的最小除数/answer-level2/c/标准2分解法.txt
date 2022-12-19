### 解题思路
二分之即可
### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA  1000000

int is_okay(int *data, int size, int div, int limit)
{
	int loop;
	int sum = 0;
	for (loop = 0; loop < size; loop++) {
		sum += (data[loop]  + div - 1) / div;
	}
	if (sum <= limit)
		return 1;
	
	return 0;
}

int partition(int *data, int size, int left, int right, int limit)
{
	int mid = (left + right) / 2;

	if (right - left == 1) {
		if (is_okay(data, size, right, limit)) {
			return right;
		}
		if (is_okay(data, size, left, limit)) {
			return left;
		}
	}
	if (is_okay(data, size, mid, limit)) {
		right = mid;
	} else {
		left = mid;
	}
	return partition(data, size, left, right, limit);
}

int smallestDivisor(int *nums, int numsSize, int threshold)
{
	if (!nums || numsSize == 0) {
		return 1;
	}
	return partition(nums, numsSize,0, MAX_DATA, threshold);
}
```