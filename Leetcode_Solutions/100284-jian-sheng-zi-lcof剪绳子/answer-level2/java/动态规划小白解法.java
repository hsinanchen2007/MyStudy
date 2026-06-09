### 解题思路
知乎高赞文章--动态规划的高度套路
https://zhuanlan.zhihu.com/p/107457744

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n==2){
            return 1;
        }else if(n==3){
            return 2;
        }
        int[] dp=new int[n+1];
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i]=Math.max(dp[i],dp[j]*dp[i-j]);
            }
        }
        return dp[n];
    }
}
```