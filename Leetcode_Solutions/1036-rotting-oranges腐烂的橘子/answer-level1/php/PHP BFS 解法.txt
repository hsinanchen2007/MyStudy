参考官方题解

```php
class Solution
{

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid)
    {
        $row = count($grid);
        if ($row == 0) return 0;
        $col = count($grid[0]);
        $directions = [[-1, 0], [0, -1], [0, 1], [1, 0]];
        $minutes = 0;
        $visited = array_fill(0, $row, array_fill(0, $col, false));
        $infected = new SplQueue();
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                // 队列中只让腐烂的橘子入队
                if ($grid[$i][$j] == 2) {
                    $visited[$i][$j] = true;
                    $infected->enqueue($i * $col + $j);
                }
            }
        }

        while ($count = $infected->count()) {
            for ($m = 0; $m < $count; ++$m) {
                // 出队时，让当前腐烂橘子四周的新鲜橘子都变为腐烂，即 grid[newX][newY] = 2
                $one = $infected->dequeue();
                $x = (int) ($one / $col);
                $y = $one % $col;
                // 每分钟每个腐烂的橘子 (2) 都会使其上下左右的新鲜橘子 (1) 腐烂
                for ($k = 0; $k < 4; ++$k) {
                    $newX = $x + $directions[$k][0];
                    $newY = $y + $directions[$k][1];
                    if (
                        $newX >= 0 && $newX < $row && $newY >= 0 && $newY < $col
                        && !$visited[$newX][$newY]
                        && $grid[$newX][$newY] == 1
                    ) {
                        $grid[$newX][$newY] = 2;
                        $visited[$newX][$newY] = true;
                        $infected->enqueue($newX * $col + $newY);
                    }
                }
            }
            $minutes++;
        }

        // 最后检查网格中是否还有新鲜的橘子, 有，返回 -1 代表 impossible; 没有则返回 minute
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                if ($grid[$i][$j] == 1) {
                    return -1;
                }
            }
        }

        // 第一批入队（出队）的不算
        return $minutes == 0 ? 0 : --$minutes;
    }
}
```
