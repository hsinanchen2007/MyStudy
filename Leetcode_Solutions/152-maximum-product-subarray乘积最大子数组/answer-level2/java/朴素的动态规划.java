### 解题思路
动态规划
状态，最大值，最小值
如果是正数就乘最大值，反之乘最小值
每次都与自身比较
### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        int Max=nums[0];
        int[][]dp=new int[nums.length][2];
        dp[0][0]=nums[0];dp[0][1]=nums[0];
        if(nums.length==1)
            return nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]>0){
                dp[i][0]=Math.max(nums[i],nums[i]*dp[i-1][0]);
                dp[i][1]=Math.min(nums[i],nums[i]*dp[i-1][1]);
            }
            else {
                dp[i][0] = Math.max(nums[i], nums[i] * dp[i - 1][1]);
                dp[i][1]=Math.min(nums[i],nums[i] * dp[ i - 1][0]);
            }
            if(Max<dp[i][0])
                Max=dp[i][0];
        }
        return Max;
    }
}
```