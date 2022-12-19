动态规划包括三个重要的概念：最优子结构、边界、状态转移公式。

f(n)为打劫前n家房子能得到的最高金额

现在分析最优子结构：
f(n)的最优子结构分为两种情况：打不打劫第n家，若打劫，则肯定不能打劫第n-1家，所以打劫前n家得到的金额为第n家的钱加上打劫前n-2家得到的最高金额，即nums(n)+f(n-2)。如果不打劫第n家，打劫前n家能得到的最高金额为打劫前n-1家能得到的最高金额，即f(n-1)。

边界条件：
f(1)=nums[1]
f(2)=max(nums[1],nums[2])

动态转移方程：
通过分析最优子结构，可以看出打劫前n家房子能得到的最高金额为f(n-2)+nums(n)与f(n-1)间的较大值，即
f(n)=max(nums[n]+f(n-2),f(n-1))

```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(i==0) dp[0]=nums[0];
            else if(i==1) dp[1]=max(nums[0],nums[1]);
            else dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
```
![image.png](https://pic.leetcode-cn.com/a5aba2a5a36ff1c859cb6e019fbfbbf056bdd2a780d3a08f278273f082880bde-image.png)
