### 思路
经典的区间dp，我们令$f(i,j)$代表删除区间$[i,j]$的最小值（即最小删除次数），那么可得以下递推公式：

$f(i,j) = \begin{Bmatrix}
 min(f(i+1, j-1), f(i, k) + f(k + 1, j))& if\:a[i] = a[j] \\
 min(f(i, j), f(i, k) + f(k + 1, j))& if\:a[i] \neq a[j]
\end{Bmatrix} i \leq k<j$

分析一下，这里根据a[i]是否等于a[j]，分两种情况。因为当a[i] = a[j]的时候，有可能产生最小删除次数的方案是a[i]和a[j]等到最后一起被删。这里提供两种版本的解法，一种是动态规划、一种是回溯+记忆化。

### 解法一 动态规划 
```java
 public int minimumMoves(int[] arr) {
        int len = arr.length;
        int[][] dp = new int[len][len];

        // 单个字符也是回文串，删除单个字符的最小删除次数就是1
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }

        for (int j = 1; j < len; j++) {
            for (int i = j-1; i >= 0; i--) {
                if (i == j - 1) {
                    // 就两个元素
                    dp[i][j] = arr[i] == arr[j] ? 1 : 2;
                    continue;
                }

                // 下面至少三个元素
                int min = Integer.MAX_VALUE;
                if (arr[i] == arr[j]) {
                    // 头尾相等，最小值有可能是出现在这对头尾最后被删的结果
                    min = dp[i+1][j-1];
                }

                for (int k = i; k < j; k++) {
                    min = Math.min(min, dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = min;
            }
        }

        return dp[0][len-1];
    }
```

### 解法二 回溯+记忆化
```java
     private int[] arr;
    private int[][] memo;

    private int backTrack(int i, int j) {
        if (i == j) {
            return 1;
        }

        if (i == j - 1) {
            // 两个数字
            return arr[i] == arr[j] ? 1 : 2;
        }

        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int min = Integer.MAX_VALUE;
        if (arr[i] == arr[j]) {
            min = backTrack(i + 1, j - 1);
        }

        for (int k = i; k < j; k++) {
            min = Math.min(min, backTrack(i, k) + backTrack(k + 1, j));
        }

        memo[i][j] = min;
        return min;
    }

    public int minimumMoves(int[] arr) {
        this.arr = arr;
        int len = arr.length;
        memo = new int[len][len];
        return backTrack(0, len - 1);
    }
```

### 复杂度
**时间复杂度**：$O(n^3)$。从dp的解法中可以发现有三个for循环，而回溯的算法加上记忆化之后本质上和dp有相同的事件复杂度，但是由于采用的是递归，因此执行效率会比dp算法略慢一些。
**空间复杂度**：$O(n^2)$。两种解法都开辟一个$n*n$的二维数组。

### 题外话
从代码可读性上来说，其实回溯算法可读性会更好一些。

最后感谢@zhaoyw1999


