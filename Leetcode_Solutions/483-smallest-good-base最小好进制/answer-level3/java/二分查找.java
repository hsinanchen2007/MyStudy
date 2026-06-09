- 就是找到一个最小的进制，它的所有位为 1，恰好表示为 n。
- 根据题意，n 的取值范围是 [3, 10^18]，这样的进制必然存在，因为存在一个 `n - 1` 进制它的表示为 `11`。
- 这里有两个变量，一个是进制，一个是对应进制下的长度。可以固定一个变量，然后判断是否满足条件即可。进制的取值范围为 `[2, n - 1]`，范围太大，所以应该固定长度，判断是否存在满足条件的进制。
- 进制越小，长度越长；进制越大，长度越短。我们可以从大到小枚举长度，判断是否存在满足条件的进制，这一步可以运用二分查找。
- 枚举长度的时间复杂度为 `O(logn)`，二分查找的时间复杂度为 `O(logn)`，辅助计算的时间复杂度为 `O(logn)`，总的时间复杂度为 `O(logn ^ 3)`。

```java
class Solution {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        for (int len = 63; len >= 2; --len) {
            long radix = getRadix(len, num);
            if (radix != -1) {
                return String.valueOf(radix);
            }
        }
        return String.valueOf(num - 1);
    }

    private long getRadix(int len, long num) {
        long l = 2, r = num - 1;
        while (l < r) {
            long mid = l + r >>> 1;
            if (calc(mid, len) >= num) r = mid;
            else l = mid + 1;
        }
        return calc(r, len) == num ? r : -1;
    }

    private long calc(long radix, int len) {
        long p = 1;
        long sum = 0;
        for (int i = 0; i < len; ++i) {
            if (Long.MAX_VALUE - sum < p) {     // 防止溢出
                return Long.MAX_VALUE;
            }
            sum += p;
            if (Long.MAX_VALUE / p < radix) {   // 防止溢出
                p = Long.MAX_VALUE;
            } else {
                p *= radix;
            }
        }
        return sum;
    }
}
```

更多题解欢迎关注 [https://github.com/Jerring/LeetCode](https://github.com/Jerring/LeetCode) ^_^