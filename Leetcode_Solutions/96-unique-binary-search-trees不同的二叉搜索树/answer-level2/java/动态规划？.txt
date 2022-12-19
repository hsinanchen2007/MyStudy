![image.png](https://pic.leetcode-cn.com/28a407bfaec1bfd50f5fb11d5b8d2cb78b6991c8acdd5ec5296125be2fe2d35d-image.png)
![image.png](https://pic.leetcode-cn.com/619414480c850caf582a3859dfe18905a8f2cc9c4d5bd4f71219ee13d430fa9c-image.png)

```java
class Solution {
    int[] dp;
    public int numTrees(int n) {
        dp = new int[n+2];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;i++){
            dp[i]=sumnumber(i);
        }
        return dp[n];
    }
    public int sumnumber(int n) {
        int result = 0;
        for(int i=1;i<=n;i++){
            result=result+dp[i-1]*dp[n-i];
        }
        return result;
    }
}
```



