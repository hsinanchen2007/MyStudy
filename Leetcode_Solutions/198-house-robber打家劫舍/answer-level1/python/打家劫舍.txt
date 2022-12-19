### 解题思路
类似按摩师，选取有条件的最大和值，迭代法求动态规划。注意空集的情况！

### 代码

```cpp []
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int dp0=0,dp1=nums[0],dp=0;
        for(int i=1;i<nums.size();i++)
        {
            dp=dp1;
            dp1=dp0+nums[i];
            dp0=max(dp0,dp);
        }
        return max(dp0,dp1);
    }
};
```
```python []
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0;
        dp0,dp1=0,nums[0]
        for i in range(1,len(nums)):
            dp0,dp1=max(dp0,dp1),dp0+nums[i]
        return max(dp0,dp1)
```

