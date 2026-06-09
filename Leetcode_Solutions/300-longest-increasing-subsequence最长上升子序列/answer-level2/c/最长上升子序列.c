### 解题思路

```
int lengthOfLIS(int* nums, int numsSize) {
	int maxLen = 0;
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize;i++) {
		int low = 0, hig = maxLen;
		while (low < hig) {
			int mid = low + (hig - low) / 2;
			if (dp[mid] < nums[i])
				low = mid + 1;
			else
				hig = mid;
		}
		dp[low] = nums[i];
		if (low == maxLen)
			maxLen++;
	}
	return maxLen;
}
```

### 代码

```c
int lengthOfLIS(int* nums, int numsSize) {
	int maxLen = 0;
	int* dp = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i < numsSize;i++) {
		int low = 0, hig = maxLen;
		while (low < hig) {
			int mid = low + (hig - low) / 2;
			if (dp[mid] < nums[i])
				low = mid + 1;
			else
				hig = mid;
		}
		dp[low] = nums[i];
		if (low == maxLen)
			maxLen++;
	}
	return maxLen;
}
```