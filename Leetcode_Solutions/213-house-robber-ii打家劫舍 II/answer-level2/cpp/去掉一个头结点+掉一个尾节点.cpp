### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
     if(nums.size()==0)  return 0;
     if(nums.size()==1)  return nums[0]; 
     if(nums.size()==2)  return max(nums[0],nums[1]);
     vector<int> dp(nums.size()-1),dps(nums.size()+1);
     int tempmax;
     dp[0]=nums[0];
     dp[1]=max(nums[0],nums[1]);
     for(int i=2;i<nums.size()-1;i++)
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);//去尾
     tempmax=dp[nums.size()-2]; 
     dps[1]=nums[1];
     dps[2]=max(nums[1],nums[2]);
     for(int i=3;i<nums.size();i++)
        dps[i]=max(dps[i-1],dps[i-2]+nums[i]);
    return max(tempmax,dps[nums.size()-1]);
      
    }
};
```
通过打家劫舍一的知识，我们可以发现这个问题就是在那个问题基础上加了一个条件，头家和尾家不可以同时偷。
所以，去掉头结点，对剩下的节点进行动态规划。
再去电为节点进行动态规划
再比较两次的结果谁大谁小。