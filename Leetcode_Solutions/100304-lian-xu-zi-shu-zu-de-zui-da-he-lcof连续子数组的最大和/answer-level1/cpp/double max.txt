### 解题思路
对于遍历的每一项，要么不断加和，要不重新统计。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = std::numeric_limits<int>::min();
        int sum = 0;

        for(auto &n : nums) {
            sum = max(sum + n, n);
            ans = max(sum, ans);
        }

        return ans;
    }
};
```