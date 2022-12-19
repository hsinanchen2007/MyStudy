
这道题看到题的第一反应就是暴力递归，但也是几乎可以直接预见，一定会超时，因为会有太多的重复计算，比如当投第三个骰子，此时总和为7的情况，可能进行了很多次运算，所以使用备忘录记录下第i次投骰子时且总和为j的情况。避免重复运算。然后进行递归即可，把每次的结果保存在备忘录中。
# 记忆化递归：
```java
    int[][] cache;

    public int numRollsToTarget(int d, int f, int target) {
        cache = new int[d][target + 1];
        for (int i = 0; i < cache.length; i++) {
            for (int j = 0; j < cache[0].length; j++) {
                cache[i][j] = -1;
            }
        }
        return v(d, 0, f, 0, target);
    }

    private int v(int d, int index, int f, int tempSum, int target) {
        //index越界或者 和超过了target 直接丢弃这种情况
        if (index > d || tempSum > target) return 0;
        if (index == d) {
            //最后一次投完后如果和等于target返回当前这种情况
            if (tempSum == target) return 1;
            else return 0;
        }
        if (cache[index][tempSum] != -1) return cache[index][tempSum];
        int res = 0;
        for (int i = 1; i <= f; i++) {
            res += v(d, index + 1, f, tempSum + i, target);
            res %= 1000000007;
        }
        cache[index][tempSum] = res;
        return cache[index][tempSum];
    }
```
# 动态规划
        在这题中dp和记忆化递归是一个思路，用上一次投的状态，计算这次的状态
        dp[i][j] 表示当摇到第i+1个骰子且当前和为j时的所有情况
        状态转移方程：dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+........d[i-1][j-f] //这里注意j-f不要越界了
        每次计算完mod一下即可


```java
public int numRollsToTarget(int d, int f, int target) {
        //dp[i][j] 表示当摇到第i+1个骰子且当前和为j时的所有情况
        int[][] dp = new int[d][target + 1];
        for (int i = 1; i <= Math.min(f, target); i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < d; i++) {
            for (int j = 1; j <= target; j++) {
                for (int k = 1; k <= f; k++) {
                    if (j >= k) {
                        dp[i][j] += dp[i - 1][j - k];
                        dp[i][j] %= 1000000007;
                    }
                }
            }
        }
        return dp[d - 1][target];
    }
```
