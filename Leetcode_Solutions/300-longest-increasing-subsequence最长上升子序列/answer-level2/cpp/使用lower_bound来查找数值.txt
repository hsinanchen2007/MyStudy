### 解题思路

使用lower_bound来查找数值

### 代码

```cpp

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int *dp = new int[nums.size()];
        fill(dp, dp + nums.size(), INT_MAX);

        for (int x : nums)
        {
            *lower_bound(dp, dp + nums.size(), x) = x;
        }

        return lower_bound(dp, dp + nums.size(), INT_MAX) - dp;
    }
};
```