### 解题思路
在62的基础上，检查障碍物。

注意：
- 开头和结尾为障碍物
- 边界的时候，检查当前是否是障碍物，以及dp前一个是否是0
- $dp[0][0] = 1;开始过滤障碍物了，并且需要检查$dp[$i - 1][0] == 0

### 性能
执行用时 :20 ms, 在所有 PHP 提交中击败了40.00%的用户
内存消耗 :15.5 MB, 在所有 PHP 提交中击败了27.27%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $obstacleGrid
     * @return Integer
     */
    function uniquePathsWithObstacles($obstacleGrid) {
        $m = count($obstacleGrid);
        $n = count($obstacleGrid[0]);
        if ($obstacleGrid[0][0] == 1 || $obstacleGrid[$m - 1][$n - 1] == 1) return 0;

        $dp = [];

        $dp[0][0] = 1;
        for ($i = 1; $i < $m; $i++) {
            if ($obstacleGrid[$i][0] == 1 || $dp[$i - 1][0] == 0) {
                $dp[$i][0] = 0;
            } else {
                $dp[$i][0] = 1;
            }
        }
        for ($j = 1; $j < $n; $j++) {
            if ($obstacleGrid[0][$j] == 1 || $dp[0][$j - 1] == 0) {
                $dp[0][$j] = 0;
            } else {
                $dp[0][$j] = 1;
            }
        }

        for ($i = 1; $i < $m; $i++) {
            for ($j = 1; $j < $n; $j++) {
                if ($obstacleGrid[$i][$j] == 1) {
                    $dp[$i][$j] = 0;
                } else {
                    $dp[$i][$j] = $dp[$i - 1][$j] + $dp[$i][$j - 1];
                }
            }
        }

        return $dp[$m - 1][$n - 1];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2) [M * N]
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/unique-paths-ii/solution/php-dong-tai-gui-hua-jie-fa-by-zzpwestlife-3/](https://leetcode-cn.com/problems/unique-paths-ii/solution/php-dong-tai-gui-hua-jie-fa-by-zzpwestlife-3/)