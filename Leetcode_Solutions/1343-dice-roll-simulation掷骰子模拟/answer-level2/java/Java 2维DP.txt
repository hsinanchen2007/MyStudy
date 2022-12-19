**准备知识**

这题从直觉上有点复杂。我们可以先从最简单的情况开始。如何计算摇n次骰子可能出现的排列数量？
很明显，答案是`6 ^ n`。因为每次摇骰子，都可能有6种可能，从数学角度，排列组合就能得出这个结论。如果我们想用动态规划去模拟整个计算过程，我们该怎么做？我们设`dp[n][i]`为摇`n`次骰子，最后一次摇出点数`i`时的排列总数：
- 首先，初值`dp[1][i]`为`1`——只摇一次骰子，每个点数都可以出现一次。
- 然后，`dp[n][i] = sum(dp[n-1][k])`，`k = 0, 1, 2, 3, 4, 5`(这里我们假设点数从0开始)。前置的所有点数都可以进一步扔出`i`。
- 其实，我们还可以进一步得出, 对于任意的`n`，`i`，`j`，都有`dp[n][i] == dp[n][j]`。因此，递推公式转变为`dp[n][i] = 6 * dp[n-1][i]`，借由初值为1，可以直接得出`dp[n][i] = 6 ^ (n - 1)`。

下面给出上述推演逻辑的DP代码，`dieSimulator(n - 1) == 6 ^ n`必定成立。
```java
class Solution {
    public int dieSimulator(int n) {
        int[][] dp = new int[n][6];
        // init, roll once, only one sequence end up by every number
        for (int i = 0; i < 6; i++) dp[0][i] = 1;
        // start dp
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                dp[i][j] = Arrays.stream(dp[i-1]).sum();
            }
        }
        return Arrays.stream(dp[n-1]).sum();
    }
}
```

**算法**
题目给出了一些额外的限制，但我们可以在上面的代码的基础上做一些修改。当我们计算`dp[n][i]`(注意，排列以`i`结尾)，我们需要注意前置有没有连续的`i`出现:
1. 如果`k != i`, 那么`dp[n-1][k]`可以直接转移到`dp[n][i]`，因为这个时候只有结尾一个`i`出现。
2. 如果`k == i`, 则只有一部分`dp[n-1][i]`可以转移到`dp[n][i]`。例如，当`i = 1`且`rollMax[i-1] = 4`时：所有的长度为`n-1`的排列中，以`1111`结尾的都不能再继续置出`1`了，否则就超出了限制。我们可以计算这些排列的数量，并将它们剔除出去。但是，如何计算呢？我们还是考虑`rollMax[0] = 4`，我们如何用`dp[n-1][k]`计算`dp[n][1]`:
	```text
	n ≤ 4   - - -             我们什么也不用做，只置了4次骰子，所以不可能出现超过4个点数1
	n = 5   1 1 1 1           置了5次骰子，我们只需要排除一种情况，就是前四次全是置出1的情况
	n = 6   x 1 1 1 1         这里x可以为0， 2， 3， 4， 5，所以我们要排除的数量为dp[0][0] + dp[0][2] + dp[0][3] + dp[0][4] + dp[0][5]
	n = 7   y x 1 1 1 1       这里x可以为0， 2， 3， 4， 5，所以我们要排除的数量为dp[1][0] + dp[1][2] + dp[1][3] + dp[1][4] + dp[1][5]
	...
	```
3. 别忘了模运算法则: 
`(a + b) % M = (a % M + b % M) % M`
`(a - b) % M = (a % M - b % M) % M`，在Java中，模运算的结果可以为负数，所以我们要引入一个额外的`M`来保证减法的正确性，即`(a % M - b % M + M) % M`
4. 在实现代码中，`dp`数组的两个维度都是从0开始的。

**复杂度**
Time: `O(n)`
Spac: `O(n)`
```java
class Solution {
    
    private static int MOD = 1000000007;
    
    public int dieSimulator(int n, int[] rollMax) {
        int[][] dp = new int[n][6];
        for (int i = 0; i < 6; i++) dp[0][i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                dp[i][j] = Arrays.stream(dp[i-1]).reduce(0, (a, b) -> (a + b) % MOD);
                // 参见算法部分第2条
                if (i == rollMax[j]) dp[i][j]--;
                else if (i > rollMax[j]) {
                    for (int k = 0; k < 6; k++) {
                        if (j != k) dp[i][j] = (dp[i][j] - dp[i - rollMax[j] - 1][k] + MOD) % MOD;
                    }
                }
            }
        }
        return Arrays.stream(dp[n-1]).reduce(0, (a, b) -> (a + b) % MOD);
    }
}
```