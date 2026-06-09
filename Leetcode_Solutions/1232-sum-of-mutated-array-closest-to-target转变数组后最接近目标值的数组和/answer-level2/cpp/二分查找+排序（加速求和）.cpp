二分查找求解阈值，通过排序可以稍微优化求和的速度。

```
int findBestValue(vector<int>& arr, int target) {
	// 排序后方便计算和
	sort(arr.begin(), arr.end());
	int low = 1, heigh = arr[arr.size() - 1];
	int res = INT_MAX, middle = low + (heigh - low) / 2;
	while (low < heigh) {
		long long int sum = 0;
		int i = 0;
		while (arr[i] < middle) {
			sum += arr[i];
			i++;
		}
		sum += (arr.size() - i) * middle;
		if (sum >= target) {
			heigh = middle;
		}
		else {
			low = middle + 1;
		}
		middle = low + (heigh - low) / 2;
	}

	// 需要比较下边界和当前的值哪个更接近求得的和接近target
	int sum1 = 0;
	int i = 0;
	while (arr[i] < low) {
		sum1 += arr[i];
		i++;
	}
	sum1 += (arr.size() - i) * low;

	int sum2 = 0;
	i = 0;
	while (arr[i] < low-1) {
		sum2 += arr[i];
		i++;
	}
	sum2 += (arr.size() - i) * (low-1);

	if (abs(sum2 - target) <= abs(sum1 - target)) {
		return low - 1;
	}
	else {
		return low;
	}
}
```
