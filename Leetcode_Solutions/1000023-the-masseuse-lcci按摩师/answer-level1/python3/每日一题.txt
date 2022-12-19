### 解题思路
此处撰写解题思路
动态规划，每一个节点分为两种情况考虑。
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = (int) nums.size();
        if( n == 0)
            return 0;
        int dp0 = 0; int dp1 = nums[0];
        for (int i = 1; i < n; ++i)
        {
            int tp0 = max(dp0, dp1);
            int tp1 = dp0 + nums[i];
            dp0 = tp0;
            dp1 = tp1;
        }
        return max(dp0, dp1);
    }
};
```