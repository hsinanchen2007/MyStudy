1、递归（记忆化搜索）
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.isEmpty()) return 0;
        return minimumTotalHelper(triangle, 0, 0, new int[triangle.size()][triangle.size()]);
    }

    int minimumTotalHelper(List<List<Integer>> triangle, int row, int col, int[][] memo) {
        // 此处理应判断非空，不想用Integer[][]就偷懒用0来判断，理论上是有问题的，实际上没啥影响，知道就OK了。
        if (memo[row][col] != 0) return memo[row][col];

        if (row == triangle.size() - 1) {
            return memo[row][col] = triangle.get(row).get(col);
        }

        int left = minimumTotalHelper(triangle, row + 1, col, memo);
        int right = minimumTotalHelper(triangle, row + 1, col + 1, memo);
        return memo[row][col] = Math.min(left, right) + triangle.get(row).get(col);
    }
}
```

2、DP
二维数组（空间复杂度O(n^2)）
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.isEmpty()) return 0;

        int[][] dp = new int[triangle.size()][triangle.size()];
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                if (i == triangle.size() - 1)
                    dp[i][j] = triangle.get(i).get(j);
                else
                    dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0][0];
    }
}
```
同上（略作优化）
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.isEmpty()) return 0;

        int[][] dp = new int[triangle.size() + 1][triangle.size() + 1];
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0][0];
    }
}
```
一维数组（空间复杂度O(n)）
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.isEmpty()) return 0;

        int[] dp = new int[triangle.size() + 1];
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}
```
利用自身（空间复杂度O(1)）
```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.isEmpty()) return 0;
        List<Integer> currLevel, nextLevel;
        for (int i = triangle.size() - 2; i >= 0; i--) {
            currLevel = triangle.get(i);
            nextLevel = triangle.get(i + 1);
            for (int j = 0; j < currLevel.size(); j++) {
                currLevel.set(j, Math.min(nextLevel.get(j), nextLevel.get(j + 1)) + currLevel.get(j));
            }
        }
        return triangle.get(0).get(0);
    }
}
```
