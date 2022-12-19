
# 方法：二分查找

## 注意：
- sum的求解方式：`sum += (piles[i] + mid - 1) / mid`

```c []
int minEatingSpeed(int* piles, int pilesSize, int H) {
    int low = 1;
    int high = 1000000001; // < INI_MAX: 2147483647
    while (low < high) {
    	int mid = low + (high - low) / 2, sum = 0;
    	for (int i = 0; i < pilesSize; i++)
    		sum += (piles[i] + mid - 1) / mid;
    	if (sum <= H)
    		high = mid;
    	else
    		low = mid + 1;
    }
    return low;
}```


