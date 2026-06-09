
### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int[] dp = new int[nums.length+1];
        int result = 0;
        for(int i=0;i<nums.length;i++){
            dp[i] = nums[i];
            if(dp[i] > result){
                result = dp[i];
            }
        }
        
        for(int i=2;i<nums.length;i++){
            int s = 0;
            if(i >= 3){
                s = dp[i-3];
            }
            dp[i] = nums[i]+ Math.max(dp[i-2], s);
            if(dp[i] > result){
                result = dp[i];
            }
        }
        return result;
    }
}
```