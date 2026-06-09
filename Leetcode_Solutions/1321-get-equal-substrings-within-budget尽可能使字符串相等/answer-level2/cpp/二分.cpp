### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        if (s.empty()) return 0;
        int n = s.size(), prefix = 0, ans = 0;
        vector<int> costs(n + 1);
        for (int i = 1; i <= n; i ++) {
            prefix += abs(s[i-1] - t[i-1]);
            costs[i] = prefix;
            int offset = costs.begin() + i - lower_bound(costs.begin(), costs.begin() + i, prefix - maxCost);
            ans = max(ans, offset);
        }
        return ans;
    }
};
```