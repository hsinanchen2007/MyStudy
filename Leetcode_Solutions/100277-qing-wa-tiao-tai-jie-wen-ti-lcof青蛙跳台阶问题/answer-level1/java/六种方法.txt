### 方法一：暴力
#### 代码
```java []
public class Solution {
    public int climbStairs(int n) {
        climb_Stairs(0, n);
    }
    public int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
}
```
#### 复杂度分析

- 时间复杂度：$O(2^n)$
- 空间复杂度：$O(n)$。

### 方法二：记忆化递归
#### 代码
```java []
public class Solution {
    public int climbStairs(int n) {
        int memo[] = new int[n + 1];
        return climb_Stairs(0, n, memo);
    }
    public int climb_Stairs(int i, int n, int memo[]) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
}
```
#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(n)$ 。
### 方法三：动态规划
此题是 [面试题10- I. fei斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/)
 的变形形式，强烈建议您先看上一题斐波那契数列的解题方法，再看这道题时边游刃有余了。

本题与上一题的不同点只有一个，即 `f(0) = 1, f(1) = 1`。

#### 代码

```python []
class Solution:
    def numWays(self, n: int) -> int:
        if n < 2:  return 1
        dp = [1 for _ in range(n+1)]
        dp[1] = 1
        for i in range(2,n+1):
            dp[i] = dp[i - 1] + dp[i - 2] 
        return dp[-1] % 1000000007  # 取模
```
```java []
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

#### 复杂度分析
- 时间复杂度：$O(N)$。我们计算了从 0 到 n 的值。
- 空间复杂度：$O(N)$。使用了数组 `dp`。

### 方法四：斐波那契数
```java []
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}
```
#### 复杂度分析
- 时间复杂度：$O(N)$。我们计算了从 0 到 n 的值。
- 空间复杂度：$O(1)$。

### 方法五：Binets 方法
#### 代码
```java []
 public class Solution {
    public int climbStairs(int n) {
        int[][] q = {{1, 1}, {1, 0}};
        int[][] res = pow(q, n);
        return res[0][0];
    }
    public int[][] pow(int[][] a, int n) {
        int[][] ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }
    public int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
```

#### 复杂度分析

- 时间复杂度：$O(log(n))$。遍历 $log(n)$ 位。
- 空间复杂度：$O(1)$。使用常量级空间。

### 方法六：斐波那契公式
#### 代码
```java []
public class Solution {
    public int climbStairs(int n) {
        double sqrt5=Math.sqrt(5);
        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
        return (int)(fibn/sqrt5);
    }
}
```
#### 复杂度分析

- 时间复杂度：$O(log(n))$。使用 `pow()` 方法。
- 空间复杂度：$O(1)$。使用常数级空间。