# 思路
位于数组每一步的时候，都有2种（位于数组头尾）或3种行走的方案，只要将这几种方案的方案数相加即可。同时，递归的时候会有很多的重复计算，因此需要记忆化来降低时间复杂度。具体代码如下：

```java
private static final int MOD = 1000000007;

    private int arrLen;
    private long[][] memo;

    private long backTrack(int from, int steps) {
        if (from == 0 && steps == 0) {
            return 1;
        }

        if (from > steps) {
            return 0;
        }

        if (memo[from][steps] != -1) {
            return memo[from][steps];
        }

        // 不动
        long nonMoveCount = backTrack(from, steps - 1);

        // 向左
        long leftMoveCount = 0;
        if (from > 0) {
            leftMoveCount = backTrack(from - 1, steps - 1);
        }

        // 向右
        long rightMoveCount = 0;
        if (from < arrLen - 1) {
            rightMoveCount = backTrack(from + 1, steps - 1);
        }

        memo[from][steps] = (nonMoveCount + leftMoveCount + rightMoveCount) % MOD;

        return memo[from][steps];
    }

    public int numWays(int steps, int arrLen) {
        // 数组长度最多就是一般的步数+1, 否则走太远就回不来了。
        this.arrLen = Math.min(arrLen, steps / 2 + 1);

        memo = new long[this.arrLen][steps + 1];
        for (int i = 0; i < this.arrLen; i++) {
            for (int j = 0; j < steps + 1; j++) {
                memo[i][j] = -1;
            }
        }
        return (int) backTrack(0, steps);
    }

```
