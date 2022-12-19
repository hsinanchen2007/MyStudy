### 解题思路
此处撰写解题思路
![QQ图片20200318202542.png](https://pic.leetcode-cn.com/9d891e97ec5513469d67cb5a5e73969e647ee9dedeae10e6330b927080d3eb2b-QQ%E5%9B%BE%E7%89%8720200318202542.png)

### 代码

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        if(nums.size() == 0)
            return 0;

        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};
```