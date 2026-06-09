这是一个挺经典的问题，解决方法有很多。这里介绍几个方法。
首先要有思路，这类问题的解决方法都类似。
总数为amount的现金换成n种不同方式的数目为：
- 将现金换成除第一种硬币之外的所有其他硬币方式的数目，加上
- 将现金amount-coin换成所有硬币方式的数目，其中coin为第一种硬币的面值
这样就包括了所有的方法。
再定义最简单的情况：
- amount==0，算作有一种方法，1
- amount<0，没有方法，0
- coin==0，算作没有方法，0
## 递归
通过上方的分析，很容易得到递归的代码
```
  public int coinChange2(int[] coins, int amount) {
        return helper(coins, 0, amount);
    }

  private int helper(int[] coins, int start, int amount) {
        if (amount == 0) return 1;
        if (amount < 0 || start == coins.length) return 0;
        return helper(coins, start + 1, amount) + helper(coins, start, amount - coins[start]);
    }
```
代码非常简单，递归代码看起来就是舒服，但是太慢了，提交超时。
这里我们可以用一个Map来减少重复计算，这里就不贴了，优化之后可以成功提交了，用时130ms，还是很慢。
递归过慢都是可以用迭代来优化的，这里我们就来优化一下。

## 动态规划
还是那个思路，只是这里我们用了一个数组来自底向上求解。
int[][] dp = new int[amount + 1][coins.length + 1]
dp是一个二维数组，一维是钱数，二维是这个钱使用多少种硬币组合，值就是组合的数目了。
代码如下：
```
      int[][] dp = new int[amount + 1][coins.length + 1];
      //设置基本条件
      for (int i = 0; i <= coins.length; i++) {
          dp[0][i] = 1;
      }
      for (int i = 1; i < amount + 1; i++) {
          for (int j = 1; j <= coins.length; j++) {
              if (i < coins[j - 1]) {
                  dp[i][j] = dp[i][j - 1];
              } else {
                  dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j];
              }
          }
      }
      return dp[amount][coins.length];
```
用时10ms，提高了很多

## 继续优化
我们发现，不需要记录从一种到所有的组合数目，它们从只有一种开始依次相加，最终得到最后的结果，所以其实不需要二维数组，只要一维数组记录每个金额对应的数目，从第一种硬币开始遍历，依次相加，最后就能得到最终的结果。与之前的不同就是遍历顺序换了一下。

```
      int[] dp = new int[amount + 1];
      dp[0] = 1;

      for (int coin : coins) {
        for (int x = coin; x < amount + 1; ++x) {
          dp[x] += dp[x - coin];
        }
      }
      return dp[amount];
```
用时4ms，又提高了不少。