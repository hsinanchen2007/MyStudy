## 分析：

- 每取一次都是`1/w`,当数值在N和K之间时，返回1，说明取到了，如果大于了N，那么返回0，说明没取到。
- 总共有`2^W`种取法，每取一次都要考虑W个数
- 由于数据量太大了，递归肯定不行，哪怕加了记忆化都没用。不过，我们可以从从自顶向下法推出自底向上法，并且对每一次的取值进行优化。

## 代码：

- 先看一下递归版本的解法，超时了但方便接下来的理解。
```java
class Solution {
    double[] memo;
    public double new21Game(int N, int K, int W) {
        memo = new double[K];
        return dfs(N, K, W, 0);
    }

    public double dfs(int n, int k, int w, int cur) {
        if (cur >= k && cur <= n) return 1;
        if (cur > n) return 0;
        if (memo[cur] != 0) return memo[cur];
        double ans = 0;
        for (int i = 1; i <= w; i++) {
            ans += dfs(n, k, w, cur + i);
        }
        memo[cur] = ans / w;
        return memo[cur];
    }
}
```
- 接着我们对照着看优化后的自底向上解法
```java
class Solution {
    public double new21Game(int N, int K, int W) {
        //自底向上法就是将自顶向下法改写。
        //参考自顶向下法就很容易可以看懂了。
        double[] dp = new double[N+W+1];
        for (int i = K; i <= N; i++) dp[i] = 1.0;//如果和在K与N之间，那么返回1
        double sum = Math.min(N - K + 1, W);//如果W比N与K之间的这段长度短，那么W之后的和是取不到的。
        for (int i = K - 1; i >= 0; --i) {
            dp[i] = sum / W;
            //由于每次递归都是调用f(i) += f(i+1) + f(i+2) ... + f(i+w)
            //所以我们自底向上dp时，从f(i)到f(i-1)只要加上f(i)，减去f(i+w)就行了。因为是从f(i)开始，到f(w-1)结束。
            sum += dp[i] - dp[i+W];
        }
        return dp[0];
    }
}
```