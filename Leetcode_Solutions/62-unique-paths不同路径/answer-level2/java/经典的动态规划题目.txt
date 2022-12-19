### 解题思路
这是一道经典的动态规划题目。

解决动态规划题目需要知道四个条件：
1. 状态：这里的状态就是路径数，也就是二维数组的元素
2. 状态方程式：因为我们知道只能从下和右走，所以我们要知道一个格子的路径就只要知道它的左边格子的所有路径和上面格子的所有路径，以此类推，`dp[i][j] = dp[i-1][j] + dp[i][j-1]`
3. 初始条件和边界条件：初始条件，因为只能从左边开始，`dp[0][0] = 1`。边界条件，二维数组的边界。
4. 编程。

### 图片
![robot_maze.png](https://pic.leetcode-cn.com/e67660cafd4f15b6e462d53520fcf6e0f78bb102c6438468bb9a75946a06688d-robot_maze.png)

### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
}
```