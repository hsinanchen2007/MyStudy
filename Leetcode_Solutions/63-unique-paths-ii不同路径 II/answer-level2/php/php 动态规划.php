```php
function uniquePathsWithObstacles($obstacleGrid)
{
    // 列
    $col = count($obstacleGrid);
    // 行
    $row = count($obstacleGrid[0]);

    // 如果一开始就是障碍，那就直接返回0
    if ($obstacleGrid[0][0] == 1) {
        return 0;
    }

    // 否则初始化第一个为1（因为所走过的0都变为1）
    $obstacleGrid[0][0] = 1;

    // 先处理列
    for ($i = 1; $i < $col; $i++) {
        // 如果当前的位置为0，表示当前没有障碍。并且前一步为1，表示前一步没有障碍，走过了就变为1
        // 那么这一步就可以变为1，否则就是有障碍，置为0
        $obstacleGrid[$i][0] = ($obstacleGrid[$i][0] == 0 && $obstacleGrid[$i-1][0] == 1) ? 1 : 0;
    }

    // 再处理行
    for ($i = 1; $i < $row; $i++) {
        $obstacleGrid[0][$i] = ($obstacleGrid[0][$i] == 0 && $obstacleGrid[0][$i-1] == 1) ? 1 : 0;
    }

    // 处理除了边界后再处理内部的元素
    for ($i = 1; $i < $col; $i++) {
        for ($j = 1; $j < $row; $j++) {

            if ($obstacleGrid[$i][$j] == 0) {
                $obstacleGrid[$i][$j] = $obstacleGrid[$i-1][$j] + $obstacleGrid[$i][$j-1];
            }else {
                $obstacleGrid[$i][$j] = 0;
            }

        }
    }

    return $obstacleGrid[$col-1][$row-1];
}
```
