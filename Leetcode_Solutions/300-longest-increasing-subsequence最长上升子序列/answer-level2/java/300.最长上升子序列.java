### 解题思路
动态规划
dp[i]=max(dp[j]+1),其中0<=j<i且nums[j]<nums[i]
result=max(dp[])

### 代码

```java
class Solution {
    int result;
    public int lengthOfLIS(int[] nums) {
        if(nums.length==0)
            return 0;
        int[] dp=new int[nums.length]; 
        result=0;
        for(int i=0;i<nums.length;i++){
            int max=0;
            int j=0;
            dp[i]=1;
            while((j>=0)&&(j<i)){
                if(nums[j]<nums[i]){
                max=Math.max(max,dp[j]);
                }
                j++;
            }
             dp[i]=max+1;
            result=Math.max(dp[i],result);
        }
return result;
    }
}

```