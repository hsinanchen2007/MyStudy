```
function uniquePathsWithObstacles($obstacleGrid)
{
        // 行
        $n = count($obstacleGrid);
        // 列
        $m = count($obstacleGrid[0]);
        $res = [0];
        $res = array_pad($res, $m, 0);
        $res[0] = 1;
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $m; $j++) {
                if ($obstacleGrid[$i][$j] == 1) {
                    $res[$j] = 0;
                } elseif ($j > 0) {
                    $res[$j] += $res[$j - 1];
                }
            }
        }
        return $res[$m - 1];
}
```