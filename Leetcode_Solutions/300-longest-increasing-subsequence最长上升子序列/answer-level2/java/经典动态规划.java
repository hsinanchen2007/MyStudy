### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
 
        int[] dp = new int[nums.length];//以i结尾的上升子序列数
        Arrays.fill(dp,1);
        int max = 0;
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = Math.max(dp[j]+1,dp[i]);
                    
                }
            }
            max = Math.max(dp[i],max);
        }
        return max;
                                
    }
}
```