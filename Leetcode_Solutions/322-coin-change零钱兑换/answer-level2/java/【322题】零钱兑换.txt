**方法一：记忆化搜索：从上往下**
```
public class Solution {
  /**
  * 思路：
  * 凑成总金额所需的最少硬币个数，就是推算依次减去一个硬币剩下金额的最少硬币组成方案。
  * 每次记录所有方案的最小值，直到遍历完成。
  */
  public int coinChange(int[] coins, int amount) {
    if (amount < 1){
      return 0;
    }
    return coinChange(coins, amount, new int[amount]);
  }

  private int coinChange(int[] coins, int rem, int[] count) {
    if (rem < 0){
      return -1;
    }
    if (rem == 0){
      return 0;
    }
    if (count[rem - 1] != 0){
      return count[rem - 1];
    }
    // 定义一个初始边界值代表需要最多硬币个数的情况。
    int min = Integer.MAX_VALUE;
    for (int coin : coins) {
      int res = coinChange(coins, rem - coin, count);
      if (res >= 0 && res < min){
        min = 1 + res;
      }
    }
    count[rem - 1] = (min == Integer.MAX_VALUE) ? -1 : min;
    return count[rem - 1];
  }
}
```

**方法二：记忆化搜索：从下往上**
```
public class Solution {
  /**
  * 思路：
  * 从最小金额所需的最少硬币个数开始记录，
  * 金额递增取硬币个数最少的方案记录，直到增到要求的金额。
  */
  public int coinChange(int[] coins, int amount) {
    int max = amount + 1;
    int[] dp = new int[amount + 1];
    // 将dp数组的每一位填充为max
    Arrays.fill(dp, max);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.length; j++) {
        if (coins[j] <= i) {
          dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }
}
```

**方法三：深度优先搜索(DFS)+剪枝**
```
class Solution {
    /**
    * 思路：
    * 从最多最大面值的硬币开始使用，依次遍历符合总金额的情况并记录每次较少的硬币个数。
    */
    int ans = Integer.MAX_VALUE;
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        dfs(coins, coins.length-1, amount, 0);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
    public void dfs(int[] coins, int index, int amount, int cnt){
        if(index < 0){
            return;
        }
        for(int c = amount / coins[index]; c >= 0; c--){
            int na = amount - c * coins[index];
            int ncnt = cnt + c;
            if(na == 0){
                ans= Math.min(ans, ncnt);
                break;// 剪枝1
            }
            if(ncnt + 1 >= ans){
                break;// 剪枝2
            }
            dfs(coins, index - 1, na, ncnt);
        }
    }
}
```
