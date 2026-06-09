添加两个中间状态，处理完成后恢复状态即可

```php
class Solution
{
    function gameOfLife(&$board)
    {
        $directions = [[-1, 0], [-1, -1], [0, -1], [1, -1], [1, 0], [1, 1], [0, 1], [-1, 1]];
        $row = count($board);
        if ($row == 0) return $board;
        $col = count($board[0]);
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                $liveCount = 0;
                for ($k = 0; $k < 8; ++$k) {
                    $newX = $i + $directions[$k][0];
                    $newY = $j + $directions[$k][1];
                    if ($newX >= 0 && $newX < $row && $newY >= 0 && $newY < $col) {
                        if ($board[$newX][$newY] == 1 || $board[$newX][$newY] == 3) $liveCount++;
                    }
                }

                // 原来死了，复活了
                if ($board[$i][$j] == 0 && $liveCount == 3) $board[$i][$j] = 2;
                // 原来活着，后来死了
                if ($board[$i][$j] == 1 && ($liveCount < 2 || $liveCount > 3)) $board[$i][$j] = 3;
            }
        }

        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                if ($board[$i][$j] == 2) $board[$i][$j] = 1;
                if ($board[$i][$j] == 3) $board[$i][$j] = 0;
            }
        }
        return $board;
    }
}
```
