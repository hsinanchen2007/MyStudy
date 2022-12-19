### 解题思路
dp[i]：以i索引结尾的最大和
如果dp[i-1]加上i对应的元素变小了，那么以i索引结尾的最大和还是以i-1结尾的最大和，这种情况最多可以推到第0个元素

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        //dp[i]：以i索引结尾的最大和
        int[] dp=new int[nums.length];
        dp[0]=nums[0];
        int max=dp[0];
        for(int i=1;i<nums.length;i++){
            dp[i]=Math.max(dp[i-1]+nums[i],nums[i]);
            max = Math.max(max,dp[i]);
        }
        return max;
    }
}
```