前n行最多包含`(n * n + n) / 2`个硬币。

从而可以在`1`到`n`之间利用二分查找做。
```
public static int arrangeCoins2(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            //如果等于最大值，直接返回
            if (cal(mid) == n)
                return mid;
            //如果大于最大值，再判断mid-1
            else if (cal(mid) > n) {
                //如果mid-1小于的话，返回mid-1
                if (cal(mid - 1) < n)
                    return mid-1;
                else right = mid - 1;
            }
            //如果小于最大值，left = mid + 1
            else left = mid + 1;
        }
        return -1;
    }
    public static int cal(int num) {
        return (num * num + num) / 2;
    }
```
