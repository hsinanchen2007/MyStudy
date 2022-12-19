# **考虑到动态规划问题的重叠子问题和最优子结构问题**```
```
```
1.对于每间房子，要么偷，要么不偷；
2.如果上间房子偷的话这间就不能偷；
3.偷本间房子的话要考虑到怎样使此子问题的金额最大化；
即`max(dp[i-1],dp[i-2]+nums[i-1]);`
*********

```
class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        int dp[len+1];
        dp[0]=0;
        if(len==0) return dp[0];
        dp[1]=nums[0];

        for(int j=2;j<len+1;j++){

            dp[j]=max(dp[j-1],dp[j-2]+nums[j-1]);
        }
        return dp[len];
    }
};
```
