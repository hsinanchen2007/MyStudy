### 解题思路
找到队列最多能够跳的距离，如果距离大于索引，那么返回true;否则返回false；
第i个索引所能到达的最远距离的用dp[i]表示：
1.如果所能到达的最大距离经过了i，那么最大距离则应该是 i+nums[i],此时(i+nums[i]>dp[i-1]>=i)
2.如果没经过，说明仍然为dp[i-1]

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int * dp = new int[len];
        dp[0]=nums[0];
        for(int i=1;i<len;i++)
        {
            if(dp[i-1]>=i) dp[i]=(i+nums[i]>dp[i-1])?(i+nums[i]):dp[i-1];
            else dp[i]=dp[i-1];
        }
        return (dp[len-1]>=len-1);
        
    }
    
};
```