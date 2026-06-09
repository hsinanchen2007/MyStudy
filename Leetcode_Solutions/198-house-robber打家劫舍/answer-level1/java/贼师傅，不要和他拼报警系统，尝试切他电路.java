### 解题思路
![QQ截图20200312160501.png](https://pic.leetcode-cn.com/4a09c67d89c76ba37f16fe8c61c8dd762421e96d8aebc51e0ffdd1292b1b03a3-QQ%E6%88%AA%E5%9B%BE20200312160501.png)

当我到了第i家时，我要么偷，那就是dp[i-2]+nums[i]；要么不偷，那就还是dp[i-1]
dp[i] = max(dp[i-2]+nums[i], dp[i-1])
### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length==0){
            return 0;
        }
       int dp_i_2=0;
       int dp_i_1=0;
       int dp=nums[0];
       for(int i=1;i<nums.length;i++){
           dp_i_2=dp_i_1;
           dp_i_1=dp;

           if(dp_i_2+nums[i]>dp_i_1){
               dp=dp_i_2+nums[i];
           }else{
               dp=dp_i_1;
           }
           
       }
       return dp;

    }
}
```