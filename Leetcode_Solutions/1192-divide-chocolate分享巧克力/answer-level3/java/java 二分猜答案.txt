### 思路
我们可以用二分来猜答案，每次试探一个总甜度,假设为`x`，如果可以找到一种分组方案可以让所有的分组的总甜度都不小于当前二分试探的这个总甜度x，那么就说明当前试探的总甜度`x`是一个可行解，而且很容易可以想到，所有小于`x`的甜度肯定也是满足要求的。因此当前`x`满足要求的话，说明可能还会存在更大的甜度，因此相当于二分中的从大于`x`的右半部分继续寻找。反之，如果当前总甜度`x`不满足要求（找不到一种分组方案使得所有的分组的总甜度都不小于`x`），则说明总甜度`x`太大了，那么我们就应该往小的找。 是的，这就是二分。
<br/>

```java
private boolean isOk(int[] arr, int k, int lower) {
        // 划分成k组，每组的和都必须大于lower
        int sum = 0;
        int count = 0;
        for (int num : arr) {
            sum += num;
            if (sum >= lower) {
                count++;
                if (count == k) {
                    return true;
                }
                sum = 0;
            }
        }
        return count >= k;
    }

    public int maximizeSweetness(int[] arr, int k) {
        // 二分猜答案
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int num : arr) {
            sum += num;
            min = Math.min(min, num);
        }

        int low = min;
        int high = sum / (k + 1);
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            if (isOk(arr, k + 1, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
```