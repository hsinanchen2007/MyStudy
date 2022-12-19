### 解题思路
$F_{sum,n-1}$： 前`n-1`种硬币组成`sum`的最少硬币数

转移方程（加入第n种硬币，面值为coin）： 前n种硬币组成sum的最少硬币数。
要么不用第n种硬币，要么用$[1, \frac{amount}{coin}]$枚第n种硬币。
  $$F_{sum,n} = Min \{ F_{sum,n-1}, F_{sum-coin,n-1}+1, F_{sum-2coin,n-1} + 2, ..., F_{sum-coin*\frac{amount}{coin},n-1}+\frac{amount}{coin}\} $$

* $N_{c}$： coin的数量
* $N_{a}$： amount的大小
* 时间复杂度： $O(N_{c}*N_{a})$
* 空间复杂度： $O(N_{a})$

### 代码1

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        // F[sum]：表示前n种硬币组成sum的最少硬币数
        // 由于计算时只使用了F[sum][n-1]，所以直接压缩掉了一维
        int[] ans = new int[amount+1];
        for (int i = 1; i <= amount; ++i) {
            ans[i] = -1;
        }

        for (int i = 0; i < coins.length; ++i) {
            int c = coins[i];          
            int N = amount / c;
            for (int sum = c; sum <= amount; ++sum) {
                // 内层循环可以优化掉
                for (int n = 1; n <= N; ++ n) {
                    int curCoins = c * n;
                    if (sum < curCoins) break;
                    if (ans[curCoins] == -1) {
                        ans[curCoins] = n;
                    }

                    if (ans[sum-curCoins] != -1 && 
                        (ans[sum] == -1 || ans[sum-curCoins] + n < ans[sum])) {
                        ans[sum] = ans[sum-curCoins] + n;
                    }
                }
            }
        }

        return ans[amount];
    }
}
```

#### 代码2
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] ans = new int[amount+1];
        for (int i = 1; i <= amount; ++i) {
            ans[i] = -1;
        }

        for (int i = 0; i < coins.length; ++i) {
            int c = coins[i];
            if (c <= amount && ans[c] == -1) ans[c] = 1;   
            // 因为sum是递增计算的，所以当计算到ans[sum]的时候，
            // ans[sum-c]已经计算过了，表示前n种硬币组成sum-c的最少硬币数
            for (int sum = c; sum <= amount; ++sum) {
                    if (ans[sum-c] != -1 && 
                        (ans[sum] == -1 || ans[sum-c] + 1 < ans[sum])) {
                        ans[sum] = ans[sum-c] + 1;
                    }
            }
        }

        return ans[amount];
    }
}
```