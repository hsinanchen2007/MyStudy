### 解题思路
二分查找猜数字。每次统计不大于所猜数字的数的个数。如果不足k个，说明猜小了，否则说明猜大了。

### 代码

```cpp
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        auto less_count = [&](int num){
            int cnt = 0;
            for (int i = 1; i <= m; ++i)
                cnt += min(num / i, n);
            return cnt;
        };
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = less_count(mid);
            if (cnt < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
```