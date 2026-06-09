参考[高分题解](https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/)

```php
class Solution {

    /**
     * @param String[][] $grid
     * @return Integer
     */
    function numIslands($grid) {
        $rows = count($grid);
        if ($rows == 0) return 0;
        $cols = count($grid[0]);
        $count = 0;
        // 四个方向数组
        $directions = [[-1, 0], [0, -1], [1, 0], [0, 1]];
        // 辅助队列
        $queue = new SplQueue();
        // 访问数组
        $visited = array_fill(0, $rows, array_fill(0, $cols, false));
        for ($i = 0; $i < $rows; ++$i) {
            for ($j = 0; $j < $cols; ++$j) {
                if (!$visited[$i][$j] && $grid[$i][$j] == '1') {
                    $count++;
                    $visited[$i][$j] = true;
                    $queue->enqueue($i * $cols + $j);
                    while ($queue->count()) {
                        $cur = $queue->dequeue();
                        $x = (int) ($cur / $cols);
                        $y = $cur % $cols;
                        for ($k = 0; $k < 4; ++$k) {
                            $newX = $x + $directions[$k][0];
                            $newY = $y + $directions[$k][1];
                            if ($this->inArea($newX, $newY, $grid)
                                && !$visited[$newX][$newY]
                                && $grid[$newX][$newY] == '1'
                            ) {
                                $visited[$newX][$newY] = true;
                                $queue->enqueue($newX * $cols + $newY);
                            }
                        }
                    }
                }
            }
        }
        return $count;
    }

    private function inArea($x, $y, $grid) 
    {
        if ($x < 0 || $y < 0) return false;
        if ($x >= count($grid) || $y >= count($grid[0])) return false;

        return true;
    }
}
```