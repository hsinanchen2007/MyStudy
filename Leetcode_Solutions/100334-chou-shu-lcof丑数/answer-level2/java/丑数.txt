### 解题思路
只包含因子2、3、5的数被称为丑数；
创建next2,next3,next5,分别*2 *3 *5，并且取其三者中的最小值，更新到对应的dp[i]中

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int i2 = 0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            int next2 =  dp[i2]*2;
            int next3 =  dp[i3]*3;
            int next5 =  dp[i5]*5;
            dp[i] = Math.min(next2,Math.min(next3,next5));
            if(dp[i]==next2){
                i2++;
            }
            if(dp[i]==next3){
                i3++;
            }
            if(dp[i]==next5){
                i5++;
            }
        }
        return dp[n-1];
    }
}
```