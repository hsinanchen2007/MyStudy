### 解题思路
分几种情况分别处理
1. 起点或终点为障碍，直接返回 0
2. 设置起点值为 1
3. 第一行和第一列特殊处理。这是本题的难点和易出错的地方。如果当前为障碍，赋值为 0，如果前一个结果为 0， 当前也赋值为 0
4. 其他格子。根据 DP 方程处理即可。

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $obstacleGrid
     * @return Integer
     */
    function uniquePathsWithObstacles($obstacleGrid) {
        // dp
        $rowCount = count($obstacleGrid);
        $columnCount = count($obstacleGrid[0]);
        $result = [];
        if ($obstacleGrid[0][0] == 1 || $obstacleGrid[$rowCount - 1][$columnCount - 1] == 1) {
            return 0;
        }

        $result[0][0] = 1;
        // the first column
        for ($i = 1; $i < $rowCount; ++$i) {
            $result[$i][0] = ($obstacleGrid[$i][0] == 1 || $result[$i - 1][0] == 0) ? 0 : 1;
        }

        // the first row
        for ($j = 1; $j < $columnCount; ++$j) {
            $result[0][$j] = ($obstacleGrid[0][$j] == 1 || $result[0][$j - 1] == 0) ? 0 : 1;
        }

        // others
        for ($i = 1; $i < $rowCount; ++$i) {
            for ($j = 1; $j < $columnCount; ++$j) {
                if ($obstacleGrid[$i][$j] == 1) {
                    $result[$i][$j] = 0;
                } else {
                    $result[$i][$j] = $result[$i - 1][$j] + $result[$i][$j - 1];
                }
            }
        }
        return $result[$rowCount - 1][$columnCount - 1];
    }
}
```