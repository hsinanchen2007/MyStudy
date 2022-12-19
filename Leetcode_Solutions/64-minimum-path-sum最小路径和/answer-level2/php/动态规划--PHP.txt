### 解题思路
动态规划, 通[leetcode 62](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-php-by-salmonl-3/)

状态：定义dp[i][j]表示到达[i, j]最小路径和。
状态转移方程：dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + $grid[$i][$j];
初始化(第一行和第一列只有一条路可走)：dp[i][0] = dp[i - 1][0] + $grid[i][0]; dp[0][j] = dp[0][$j - 1] + $grid[0][$j - 1];

### 性能
执行用时 :52 ms, 在所有 PHP 提交中击败了5.00%的用户
内存消耗 :18.4 MB, 在所有 PHP 提交中击败了30.77%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function minPathSum($grid) {
        $m = count($grid);
        $n = count($grid[0]);
        if ($m <= 0 || $n <= 0) return 0;

        $dp = [];
        $dp[0][0] = $grid[0][0];
        
        for ($i = 1; $i < $m; $i++) {
            $dp[$i][0] = $dp[$i - 1][0] + $grid[$i][0];
        }

        for ($j = 0; $j < $n; $j++) {
            $dp[0][$j] = $dp[0][$j - 1] + $grid[0][$j];
        }

        for ($i = 1; $i < $m; $i++) {
            for ($j = 1; $j < $n; $j++) {
                $dp[$i][$j] = min($dp[$i - 1][$j], $dp[$i][$j - 1]) + $grid[$i][$j];
            }
        }

        return $dp[$m - 1][$n - 1];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/minimum-path-sum/comments/72722](https://leetcode-cn.com/problems/minimum-path-sum/comments/72722)