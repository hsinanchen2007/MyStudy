```java
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int maxLen=0,res=0; //maxLen：递增子序列的最大长度，res：maxLen长递增子序列的个数
        int n=nums.length;
        //dp[k][0]：以nums[k]为尾的子序列的最大长度
        //dp[k][1]：以nums[k]为尾，dp[k][0]长的子序列的个数
        int[][] dp=new int[n][2];
        for(int k=0;k<n;k++){
            dp[k][0]=dp[k][1]=1; //初始化
            for(int i=k-1;i>=0;i--){
                if(nums[k]>nums[i]){
                    if(dp[i][0]+1>dp[k][0]){ //存在更大长度，则更新最大长度及其个数
                        dp[k][0]=dp[i][0]+1;
                        dp[k][1]=dp[i][1];
                    }
                    else if(dp[i][0]+1==dp[k][0]){
                        dp[k][1]+=dp[i][1]; //存在相同最大长度，累计最大长度个数
                    }
                }
            }
            if(maxLen<dp[k][0]) maxLen=dp[k][0]; //记录最大长度
        }
        for(int[] num:dp) res=num[0]==maxLen?res+num[1]:res; //计算最大长度总个数
        return res;
    }
}
```
