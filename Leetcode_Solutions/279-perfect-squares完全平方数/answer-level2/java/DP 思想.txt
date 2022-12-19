
![20160604170107528.png](https://pic.leetcode-cn.com/91648d449127dee74de5225b27d7b7d559001a17b708f3b6c3e5a92aabc6453f-20160604170107528.png)
如图所示，红色部分表示平方数，所有的完美平方数都可以看做一个普通数加上一个完美平方数

```java
class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            dp[i] = i; // 最坏的情况就是每次+1
            for (int j = 1; i - j*j >= 0; j++) {
                // 每个完美平方数都是由一个完全平方数和一个普通数字组成
                // +1 指的是一个完全平方数
                dp[i] = Math.min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
}
```