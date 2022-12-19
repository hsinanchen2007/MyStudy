### 解题思路
  动态规划的重点就在于最优解关系的寻找，自己再寻找出初始条件（dp[0],dp[1]等）即可。


  本题就是设dp[i] 为数组下标为 0 - i 的最优解，关键在于dp[i]和之前的dp[i-1]或者dp[i-2]等的关系，分为取nums[i]和不取nums[i]两种情况，即可得出关系式：dp[i] = max(dp[i - 2] + nums[i],dp[i - 1 ]);随后自底向上依次计算dp值即可。



### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int dp[nums.size()] ;
        dp[0] = nums[0];
        
        for(int i = 1;i  < nums.size();i++){
            if(i == 1) dp[i] = max(nums[0],nums[1]);
            else{
                dp[i] = max(dp[i - 2] + nums[i],dp[i - 1 ]);
            }
        }

        return dp[nums.size() - 1];
    }
};
```