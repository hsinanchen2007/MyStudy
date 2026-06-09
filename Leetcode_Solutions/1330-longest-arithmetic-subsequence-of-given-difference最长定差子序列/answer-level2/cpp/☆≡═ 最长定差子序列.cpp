1. 记录 k 结尾的子序列长度 times[k]
2. k 结尾的子序列 长度为 比 k - difference 的长度多1。

```
class Solution {
public:
    int longestSubsequence(const vector<int>& arr, int difference) {
        unordered_map<int, int> times;
        int ans = 0;
        for (const auto i : arr) {
            times[i] = times[i - difference] + 1;
            ans = max(ans, times[i]);
        }
        return ans;
    }
};
```
