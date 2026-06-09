### 解题思路
1. 状态表示 dp[i] 第i个位置的最长上升子序列
2. 状态递归 dp[i]=1+max(dp[j] j<i and nums[j]<nums[i]>>)
3. 求最大
### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //最长上升子序列 最长非降序子序列
        //动态
        //o(n^2)  
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        vector<int> dp(nums.size(),0);
        dp[0]=1;
        // 思路 dp[i]表示
        for(int i=1;i<nums.size();i++){
            int max1=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    max1=max(dp[j],max1);
                }
            }
            dp[i]=max1+1; //这个1代表了本身
        }
        int res=dp[0];
        for(int i=1;i<nums.size();i++){

            res=max(res,dp[i]);
        
        }
        //return dp[i] 哪个值最大
        return res; 
    }
};
```