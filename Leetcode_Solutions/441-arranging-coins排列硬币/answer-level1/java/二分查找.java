实际上就是求满足 `i * (i + 1) / 2 <= n` 的最大的那个 `i`，运用二分查找即可。
```java
class Solution {
    public int arrangeCoins(int n) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r + 1 >>> 1;
            if (1L * mid * (mid + 1) / 2 <= n) l = mid;
            else r = mid - 1;
        }
        return r;
    }
}
```
更多题解欢迎关注 [https://github.com/Jerring/LeetCode](https://github.com/Jerring/LeetCode) ^_^
