### 解题思路
//dp[i]表示长度为i的绳子最大乘积
//分为两种情况：
//① 这段绳子不剪了 ，对应dp[i]不变
//② 从j处剪一刀
//      这里又分为两种情况：剪完一刀还需不需要剪
//          1.不用剪了 j*(i-j)
//          2.还得再剪： ---> 剪[0,j]段  (i-j)*dp[j]
//                      ---> 剪[j,i-j]段  j*dp[i-j]
//最后取最大值即可

### 代码

```java
class Solution {
    public int cuttingRope(int n) {

        int[] dp = new int[n+1];
        //dp[i]表示长度为i的绳子最大乘积
        //分为两种情况：
        //① 这段绳子不剪了 ，对应dp[i]不变
        //② 从j处剪一刀
        //      这里又分为两种情况：剪完一刀还需不需要剪
        //          1.不用剪了 j*(i-j)
        //          2.还得再剪： ---> 剪[0,j]段  (i-j)*dp[j]
        //                      ---> 剪[j,i-j]段  j*dp[i-j]
        //最后取最大值即可
        dp[2] = 1;
        // dp[3] = 2;
        for(int i =3;i<dp.length;i++){
            for(int j = 0;j < i;j++){
                dp[i] = Math.max(dp[i], 
                Math.max(
                    Math.max(j*dp[i-j],(i-j)*dp[j])
                    ,j*(i-j)));
            }
        }
        return dp[n];
    }
}
```