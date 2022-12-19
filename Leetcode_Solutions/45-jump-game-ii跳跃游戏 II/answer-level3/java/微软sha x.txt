### 解题思路
划区

### 代码

```java
class Solution {
    // public int jump(int[] nums) {
    //     if (nums.length == 0)
    //         return 0 ;
    //     int[] dp = new int[nums.length] ;
    //     Arrays.fill(dp,Integer.MAX_VALUE) ;
    //     dp[0] = 0 ;
    //     for (int i=1 ; i <nums.length ;i++) {
    //         for (int j=0 ; j<i ; j++) {
    //             if (nums[j] >= (i - j))
    //                 dp[i] = Math.min(dp[i],dp[j] + 1) ;
    //         }
    //     }
    //     return dp[nums.length-1] ;
    // }
    public int jump(int[] nums) {
        if (nums.length <=1 )
            return 0 ;
        int i = 0 ;
        int ret = 1;
        int nextMax =   nums[0]  ;

        while (true) {
            int curRoundNextMax = nextMax ;
            if (curRoundNextMax >= nums.length -1)
                return ret ;
            for (int j = i ; j <= curRoundNextMax ; j ++) {
                nextMax = Math.max(nextMax,j + nums[j]) ;
            }
            i = curRoundNextMax + 1 ;
            ret ++ ;
        }
    }
}
```