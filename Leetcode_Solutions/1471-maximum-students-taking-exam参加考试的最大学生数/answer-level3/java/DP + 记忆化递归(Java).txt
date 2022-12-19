# 思路
每一行的落座情况仅和上一行相关，因此用preMask表示上一行的落座情况，curMask表示当前的落座情况，递推求解即可。

# DP
```
// time complexity O(n * 2 ^ (2 * m))
class Solution {

  public int maxStudents(char[][] seats) {
    int n = seats.length, m = seats[0].length;
    int[][] dp = new int[n + 1][1 << m];
    for(int i = n - 1; i >= 0; i--){
      for(int preMask = 0; preMask < (1 << m); preMask++){
        int res = 0;
        for(int curMask = 0; curMask < (1 << m); curMask++){
          if(isValid(curMask, preMask, seats, i)){
            res = Math.max(res, Integer.bitCount(curMask) + dp[i + 1][curMask]);
          }
        }
        dp[i][preMask] = res;
      }
    }
    return dp[0][0];
  }

  private boolean isValid(int mask, int preMask, char[][] seats, int r) {
    int m = seats[0].length;
    for (int i = 0; i < m; i++) {
      if ((mask & (1 << i)) == 0) {
        continue;
      }
      if (seats[r][i] == '#') {
        return false;
      }
      if (i > 0 && seats[r][i - 1] == '.' && (mask & (1 << (i - 1))) != 0) {
        return false;
      }
      if (i < m - 1 && seats[r][i + 1] == '.' && (mask & (1 << (i + 1))) != 0) {
        return false;
      }
      if (r > 0 && i > 0 && seats[r - 1][i - 1] == '.' && (preMask & (1 << (i - 1))) != 0) {
        return false;
      }
      if (r > 0 && i < m - 1 && seats[r - 1][i + 1] == '.' && (preMask & (1 << (i + 1))) != 0) {
        return false;
      }
    }
    return true;
  }
}
```

# 记忆化递归
```
// time complexity O(n * 2 ^ (2 * m))
class Solution {
    public int maxStudents(char[][] seats) {
        int n = seats.length, m = seats[0].length;
        Integer[][] memo = new Integer[n][1 << m];
        return dfs(seats, memo, 0, 0);
    }

    private int dfs(char[][] seats, Integer[][] memo, int r, int preMask){
        int n = seats.length, m = seats[0].length;
        if(r == n){
            return 0;
        }
        if(memo[r][preMask] != null){
            return memo[r][preMask];
        }
        int res = 0;
        for(int i = 0 ; i < (1 << m) ;i++){
            if(isValid(i, preMask, seats, r)){
                res = Math.max(res, Integer.bitCount(i) + dfs(seats, memo, r + 1, i));
            }
        }
        memo[r][preMask] = res;
        return res;
    }

    private boolean isValid(int mask, int preMask, char[][] seats, int r){
        int n = seats.length, m = seats[0].length;
        for(int i = 0 ; i < m; i++){
            if((mask & (1 << i)) == 0){
                continue;
            }
            if (seats[r][i] == '#'){
                return false;
            }
            if(i > 0 && seats[r][i - 1] == '.' && (mask & (1 << (i - 1))) != 0){
                return false;
            }
            if(i < m - 1 && seats[r][i + 1] == '.' && (mask & (1 << (i + 1))) != 0){
                return false;
            }
            if(r > 0 && i > 0 && seats[r - 1][i - 1] == '.' && (preMask & (1 << (i - 1))) != 0){
                return false;
            }
            if(r > 0 && i < m - 1 && seats[r - 1][i + 1] == '.' && (preMask & (1 << (i + 1))) != 0){
                return false;
            }
        }
        return true;
    }
}
```

# 运行速度
我跑的测试结果中，记忆化递归为6ms，DP为46ms, 这是这两种方法典型的优缺点了，在这里还是记录一下。

## 记忆化递归
记忆化递归其实是带memo的DFS，自顶向下，因此会有额外的方法栈的开销。但它的好处就是按需求解，即memo中的状态不需要全部求出，而是仅求出会发生的情况。在这里很显然求某行的状态时，上一行的状态一般来说会远小于`2^m`。因此本题中它的效率高很多。

## DP
DP由于是递推求解，不需要方法栈开销，但它是自底向上，需要将所有中间状态全部求出。本题中很多中间态是不会达到的，因此多求了很多无用的状态导致效率降低。

## 总结
当定义的状态在题目中全部有效时，DP方法由于不需要栈开销效率会更高；当无效状态较多时，记忆化递归的方法会更高效。