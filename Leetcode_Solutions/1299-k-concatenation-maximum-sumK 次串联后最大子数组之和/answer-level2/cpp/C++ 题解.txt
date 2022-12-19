### 解题思路
关键点在：
1，arr的数组和是正数还是负数
2，k是否大于1

### 代码

```cpp
class Solution {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if (arr.empty() || k == 0) return 0;
        ll s = accumulate(arr.begin(), arr.end(), 0LL);
        ll s1 = 0;
        ll m = 0;
        for (auto x : arr) {
            s1 = max(s1, 0LL) + x;
            m = max(m, s1);
        }
        if (k == 1) return m;
        for (auto x : arr) {
            s1 = max(s1, 0LL) + x;
            m = max(m, s1);
        }
        if (k == 2 || s <= 0) return m;
        return ((m + (k - 2) * (s % M)) % M + M) % M;
    }
};
```

![image.png](https://pic.leetcode-cn.com/d13246a83c0bcbb0e925c029a24dca8d70c07b88b6b7f84d6ea6c40c28803df1-image.png)
