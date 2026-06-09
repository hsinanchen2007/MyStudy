### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums==null||nums.length==0) return 0;
        int n=nums.length;
        if(n==1) return nums[0];
        return Math.max(rob(nums,0,n-2),rob(nums,1,n-1));       
    }
    private int rob(int[]nums,int s,int e){
        int n=nums.length;
        if(e-s==0) return nums[s];
        if(e-s==1) return Math.max(nums[s],nums[s+1]);
        int[]dp=new int[n];
        dp[s]=nums[s];
        dp[s+1]=nums[s+1];
        dp[s+2]=nums[s]+nums[s+2];
        for(int i=s+3;i<=e;i++){
            dp[i]=Math.max(dp[i-2],dp[i-3])+nums[i];
        }
        return Math.max(dp[e-1],dp[e]);
    }
}
```