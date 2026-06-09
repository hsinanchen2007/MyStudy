给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？

这个是官方的进阶要求。。。可是我不会写O(n*sizeof(integer))的解答。。。。。

```java
class Solution {
    public int[] countBits(int num) {
        int[] dp = new int[num+1];
        boolean flag = true;
        dp[0] = 0;
        for(int i=1;i<=num;i++){
            if(flag) {
                dp[i] = dp[i-1]+1;
            }else {
                dp[i] = dp[i/2];
            }
            flag = !flag;
        }
        return dp;
    }
}
```

