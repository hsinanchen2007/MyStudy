### 解题思路
dp，动态规划经典题型。用dp数组存在下标i时，能得到的最大序列和。这个序列和有两个可能性，1、nums[i]本身；2、nums[i]+到i-1下标所达到的最大和（dp[i-1])。
为了加快速度，不另外新建dp数组，直接修改在原nums数组上。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0) nums[i]+=nums[i-1];
            if(nums[i]>ans) ans=nums[i];
        }
        return ans;
    }
};
```