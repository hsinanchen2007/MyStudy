### 解题思路
此处撰写解题思路
动态规划
dp[0]=nums[0]
dp[1]=max(nums[0], nums[1])
dp[i]=max(dp[i-1], dp[i-2]+nums[i])

return res[nums.size()-1]
### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        if(!nums.size())
        return 0;
        int res[nums.size()];
        if(nums.size()>0)
        res[0]=nums[0];
        if(nums.size()>1)
        res[1]=max(nums[0], nums[1]);
        for(int i=2;i<nums.size();i++) {
            res[i]=max(res[i-1], res[i-2]+nums[i]);
        }
        return res[nums.size()-1];
    }
};
```