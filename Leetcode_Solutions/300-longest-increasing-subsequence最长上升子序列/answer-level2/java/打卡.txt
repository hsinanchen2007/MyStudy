### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length;
        if(n==0){
            return 0;
        }
        int[] dp=new int[n];
        dp[0]=1;
        int maxans=1;
        int i,j;
        for(i=1;i<n;i++){
            int maxval=0;
            for(j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    maxval=Math.max(maxval,dp[j]);
                }
            }
            dp[i]=maxval+1;
            maxans=Math.max(dp[i],maxans);
        }
        return maxans;
            
    }
}
```