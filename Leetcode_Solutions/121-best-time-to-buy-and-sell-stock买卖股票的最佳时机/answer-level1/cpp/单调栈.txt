### 解题思路
单调栈，直接用数组倒序遍历一遍

### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int max = 0;
        vector<int> nums(prices.size());
        nums[nums.size() - 1] = prices.back();
        for(int i = prices.size() - 1; i > 0; i--)
        {
            nums[i - 1] = std::max(prices[i - 1], nums[i]);
        }

        for(int i = 0; i < prices.size(); i++)
        {
            max = std::max(max, nums[i] -  prices[i]);
        }
        return max;
    }
};
```