## 记忆化递归

+ 首先定义两个数组：

  + count：用来记录从当前位置跳，能够跳到的下一个位置
  + mem： 备忘录，用来记录当跳在第i个位置且剩余跳跃次数为j时候的所有拨号情况,避免多次重复计算

  

  ```java
  	int[][] count;
      int mod = 1000000007;
      long[][] mem;
      public int knightDialer(int N) {
          count = new int[][]{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
          mem = new long[10][N];
          long res = 0;
          for (int i = 0; i <= 9; i++) res += dfs(i, N - 1);
          return (int) (res % mod);
      }
  
      private long dfs(int k, int n) {
          if (n < 0) return 0;
          if (mem[k][n] != 0) return mem[k][n];
          if (n == 0){
              mem[k][n]=1;
              return 1;
          }
          long tmp = 0;
          for (int i : count[k]) tmp += dfs(i, n - 1);
          mem[k][n] = tmp;
          return mem[k][n]%mod;
      }
  ```

  
## 动态规划

```java
    public int knightDialer(int N) {
        int[][] count;
        int mod = 1000000007;
        count = new int[][]{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        long[][] dp = new long[10][N];
        for (int i = 0; i < 10; i++) dp[i][0] = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= 9; j++) {
                long temp = 0;
                for (int k : count[j]) temp += (dp[k][i - 1]);
                dp[j][i] = temp % mod;
            }
        }
        long res = 0;
        for (int i = 0; i < 10; i++) res = (res + dp[i][N - 1]) % mod;
        return (int) res;
    }

```

