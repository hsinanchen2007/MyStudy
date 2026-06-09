### 解题思路
参考了大牛的
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
        $m = count($grid);
        $n = count($grid[0]);
        $queue = new SplQueue();

        $count = 0;
        foreach ($grid as $key => $val) {
            foreach ($val as $k => $v) {
                if ($v == 1) {
                    $count++;
                } else if ($v == 2) {
                    $queue->push([$key, $k]);
                }
            }
        }

        $round = 0;
        while ($count > 0 && !$queue->isEmpty()) {
            $round++;
            $queueCount = $queue->count();
            for ($i = 0; $i < $queueCount; $i++) {
                $orange = $queue->shift();

                $r = $orange[0];
                $c = $orange[1];
                // 外层左侧
                if ($r - 1 >= 0 && $grid[$r - 1][$c] == 1) {
                    $grid[$r - 1][$c] = 2;
                    $count--;
                    $queue->push([$r - 1, $c]);
                }

                // 外层右侧
                if ($r + 1 < $m && $grid[$r + 1][$c] == 1) {
                    $grid[$r + 1][$c] = 2;
                    $count--;
                    $queue->push([$r + 1, $c]);
                }

                // 内层左侧
                if ($c - 1 >= 0 && $grid[$r][$c - 1] == 1) {
                    $grid[$r][$c - 1] = 2;
                    $count--;
                    $queue->push([$r, $c - 1]);
                }

                // 内层右侧
                if ($c + 1 < $n && $grid[$r][$c + 1] == 1) {
                    $grid[$r][$c + 1] = 2;
                    $count--;
                    $queue->push([$r, $c + 1]);
                }
            }

        }

        if ($count > 0) {
            return -1;
        } else {
            return $round;
        }    }
}
```