**递归 + 记忆化（自顶向下）**
常规思路
```java
class Solution {
    public int cuttingRope(int n) {
        return cuttingRopeHelper(n, new int[n + 1]);
    }

    int cuttingRopeHelper(int n, int[] memo) {
        if (n <= 2) return 1;
        if (memo[n] > 0) return memo[n];
        int max = 0;
        for (int i = 2; i < n; i++) { // 为什么循环不从1开始，因为x*1=x，所以从1开始没意义
            int cut = i * cuttingRopeHelper(n - i, memo); // 剩下的还要剪
            int notCut = i * (n - i); // 剩下的不剪了
            max = Math.max(max, Math.max(cut, notCut));
        }
        return memo[n] = max;
    }
}
```

**动态规划（自底向上）**
同上解一模一样的思路，在剩下的剪和不剪间取最大值
DP方程：
dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]))
```java
class Solution {
    public int cuttingRope(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                dp[i] = Math.max(dp[i], Math.max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
}
```

**动态规划（完全背包问题）**
从题解区看到的，确实没想到。
问题转换：绳子的长度为n，剪为长度j（1<=j<=n）的子段，求每段绳子长度的最大乘积
DP方程：
dp[i] = max(dp[i], dp[i - j] * i)
```java
class Solution {
    public int cuttingRope(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= (n + 1) / 2; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] = Math.max(dp[j], dp[j - i] * i);
            }
        }
        return dp[n];
    }
}
```

**数学解法**
神奇的数学解法，无敌了！
切分越多，乘积越大，优先级最高的长度为3。
```java
class Solution {
    public int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int s = 1;
        while (n > 4) {
            s *= 3;
            n -= 3;
        }
        return s * n;
    }
}
```
