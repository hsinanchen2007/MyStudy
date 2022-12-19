## 使用 BFS 解法
```java
class Solution {
  public int numSquares(int n) {
    Queue<Integer> queue = new LinkedList<>();
    Set<Integer> visited = new HashSet<>();

    queue.offer(0);
    visited.add(0);

    int distance = 0;

    while (!queue.isEmpty()) {
      distance++;

      int queueSize = queue.size();
      for (int i = 0; i < queueSize; i++) {
        int curr = queue.poll();
        for (int j = 1; j * j + curr <= n; j++) {
          int next = j * j + curr;
          if (next == n) {
            return distance;
          } else if (next < n && !visited.contains(next)) {
            queue.offer(next);
            visited.add(next);
          }
        }
      }
    }

    return distance;
  }
}
```

## 使用动态规划 Dynamic Programming 解法
```java 
class Solution {
  public int numSquares(int n) {
    int[] dp = new int[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      dp[i] = i;
      for (int j = 1; j * j <= i; j++) {
        dp[i] = Math.min(dp[i], dp[i - j * j] + 1);
      }
    }

    return dp[n];
  }
}
```

## 使用记忆化搜索 Memoization Search 解法

```java
class Solution {
  public int numSquares(int n) {
    if (n <= 1) {
      return n;
    }

    Integer[] memo = new Integer[n + 1];

    return memoHelper(n, memo);
  }

  private int memoHelper(int n, Integer[] memo) {
    if (n == 0) {
      return 0;
    }

    if (memo[n] != null) {
      return memo[n];
    }

    int result = n;

    for (int i = 1; i * i <= n; i++) {
      result = Math.min(result, memoHelper(n - i * i, memo) + 1);
    }

    memo[n] = result;

    return memo[n];
  }
}
```

## 使用 DFS 解法

```java
class Solution {
  public int numSquares(int n) {
		if (n <= 1) {
      return n;
    }

    return dfsHelper(n);
  }
	
  private int dfsHelper(int n) {
    if (n == 0) {
      return 0;
    }

    int result = n;

    for (int i = 1; i * i <= n; i++) {
      result = Math.min(result, dfsHelper(n - i * i) + 1);
    }

    return result;
  }
}
```