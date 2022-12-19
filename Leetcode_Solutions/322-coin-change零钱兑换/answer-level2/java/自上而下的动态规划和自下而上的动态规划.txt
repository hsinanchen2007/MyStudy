### 解题思路
#### 自上而下的动态规划
已知我们有coins这些种类的硬币硬币,要组成amount的总值,我们转换成从coins里一个个取硬币,每一次都可以取不大于剩余amount
的面额的硬币,还剩amount-coin需要取,如此递归,然后对每一层的递归结果取最小值,就是最终的最小数量了.
```java
int dp[];

        public int coinChange(int[] coins, int amount) {
            dp = new int[amount + 1];
            return getNum(coins, amount);
        }

        public int getNum(int[] coins, int amount) {
            if (amount == 0) {
                return 0;
            }
            if (dp[amount] == 0) {
                int temp = Integer.MAX_VALUE;
                for (int coin : coins) {
                    if (coin <= amount) {
                        int result = getNum(coins, amount - coin) + 1;
                        if (result > 0 && result < temp) {
                            temp = result;
                        }
                    }
                }
                if (temp == Integer.MAX_VALUE) {
                    dp[amount] = -1;
                } else {
                    dp[amount] = temp;
                }
            }
            return dp[amount];

        }
```
#### 自下而上的动态规划
可以看到,再上一步里面,我们要考虑所有的组成情况,然后拿来比较,那么,我们也可以计算amount从小到大的最优解,每一步的结果保存在dp[]中.这样,每一步都可以利用之前算出的结果了.还可以进行显式的递归,而不是隐式的递归了.

```java
class Solution {

  public int coinChange(int[] coins, int amount) {
        int dp[] = new int[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int temp = Integer.MAX_VALUE;
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    int result = dp[i - coins[j]] + 1;
                    if (result > 0 && result < temp) {
                        temp = result;
                    }
                }
            }
            if (temp == Integer.MAX_VALUE) {
                dp[i] = -1;
            } else {
                dp[i] = temp;
            }
        }
        return dp[amount];
    }
}

```

####
两种动态规划的方法时间复杂度是一样的,但是自上而下的动态规划耗时42ms,自下而上的动态规划耗时15ms,明显比上一种方法快很多,可能是取之前的结果的时候,直接从dp[]里面取了,而不用多调用一层getNum()方法.