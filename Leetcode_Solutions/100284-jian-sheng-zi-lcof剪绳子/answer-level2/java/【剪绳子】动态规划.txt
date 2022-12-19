### 题目
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 `m` 段（`m`、`n`都是整数，`n > 1`并且`m > 1`），每段绳子的长度记为 `k[0]`,`k[1]`, ... ,`k[m]` 。请问 `k[0]` * `k[1]` *... * `k[m]` 可能的最大乘积是多少？例如，当绳子的长度是`8`时，我们把它剪成长度分别为`2`、`3`、`3`的三段，此时得到的最大乘积是`18`。

### 样例
>示例 1：
**输入**: `2`
**输出**: `1`
**解释**: `2 = 1 + 1`, `1 × 1 = 1`

> 示例 2:
**输入**: `10`
**输出**: `36`
**解释**: `10 = 3 + 3 + 4`, `3 × 3 × 4 = 36`

**提示：**`2 <= n <= 58`

### 思路
这道题和整数分解除了题面描述不一样，解题思路完全是一样的。
[https://leetcode-cn.com/problems/integer-break/solution/bao-li-sou-suo-ji-yi-hua-sou-suo-dong-tai-gui-hua-/](https://leetcode-cn.com/problems/integer-break/solution/bao-li-sou-suo-ji-yi-hua-sou-suo-dong-tai-gui-hua-/)

首先，这题很容易想到递归：对于一个长度为n的绳子，设`F(n)`为长度为`n`的绳子间断后的最大乘积，那么有：
> **`F(n) = max{i * F(n - i), i * (n - i)}, i = 1, 2, ... , n - 1`**

`i * (n - i)` 表示剪成两段，`i * F(n - i)` 表示分成将 `n- i`的这段继续剪。


显然，对于这种表达式我们可以通过记忆化或者`dp`进行优化，具体过程可以参照上面那个链接。

### 代码


```java
class Solution {
    public int cuttingRope(int n) {
        if (n < 2) {
            return 0;
        }
        int[] dp = new int[n + 1];
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = Math.max(Math.max(j * dp[i - j], j * (i - j)), dp[i]);
            }
        }
        return dp[n];
    }
}
```