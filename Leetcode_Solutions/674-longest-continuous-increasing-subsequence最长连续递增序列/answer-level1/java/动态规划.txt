### 解题思路
此处撰写解题思路

### 代码

```java
/*
动态规划:
dp[i] 存储到以nums[i]结尾数字的最优解(最大长度)
若nums[i] > nums[i-1]   dp[i] = dp[i-1] + 1 ;
否则   dp[i] = 1 ;
*/

class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if( 0 ==  nums.length )  return 0 ;
        if( 1 ==  nums.length )  return 1 ;
        int []  dp = new  int[nums.length] ;
        int  max_len = 1 ;
        dp[0] = 1 ;
        for( int i = 1 ; i<nums.length ; i++ )
        {
            if(nums[i] > nums[i-1] )
            {
                dp[i] = dp[i-1]  + 1 ;
            }else{
                dp[i] = 1 ;
            }
            if(max_len>dp[i])  max_len = max_len ;
            else  max_len = dp[i] ;
        }
        return  max_len ; //返回最大长度
    }
}
```