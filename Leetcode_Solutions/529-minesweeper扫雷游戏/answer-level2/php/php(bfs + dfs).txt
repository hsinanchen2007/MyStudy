# **DFS**
```php
class Solution {

    /**
     * dfs
     * @param String[][] $board
     * @param Integer[] $click
     * @return String[][]
     */
    function updateBoard($board, $click) {
        $n = count($board);
        $m = count($board[0]);
        $this->dfs($board, $click, $n, $m);
        return $board;
    }
    function dfs(&$board, $click, $n, $m) {
        [$row, $col] = $click;
        //判断是不是地雷
        if ($board[$row][$col] == 'M' || $board[$row][$col] == 'X') {
            $board[$row][$col] = 'X';
        } else {
            //不是地雷， 计算周围是地雷的个数
            $count = 0;
            foreach([-1, 0, 1] as $i) {
                foreach([-1, 0, 1] as $j) {
                    if ($i == 0 && $j == 0) continue;
                    $r = $row + $i;
                    $c = $col + $j;
                    if ($r < 0 || $c < 0 || $r >= $n || $c >= $m) continue;
                    if ($board[$r][$c] == 'M' || $board[$r][$c] == 'X') $count++;
                }
            }
            //有地雷，标注地雷的个数
            if ($count > 0) {
                $board[$row][$col] = (string)$count;
            } else {
                //没有地雷，标注为B
                $board[$row][$col] = 'B';
                foreach([-1, 0, 1] as $i) {
                    foreach([-1, 0, 1] as $j) {
                        if ($i == 0 && $j == 0) continue;
                        $r = $row + $i;
                        $c = $col + $j;
                        if ($r < 0 || $c < 0 || $r >= $n || $c >= $m) continue;
                        if ($board[$r][$c] == 'E') $this->dfs($board, [$r, $c], $n, $m);
                    }
                }
            }
        }
    }
}
```
# **BFS**
```php
class Solution {

    /**
     * dfs
     * @param String[][] $board
     * @param Integer[] $click
     * @return String[][]
     */
    function updateBoard($board, $click) {
        $n = count($board);
        $m = count($board[0]);
        $this->dfs($board, $click, $n, $m);
        return $board;
    }
    function dfs(&$board, $click, $n, $m) {
        [$row, $col] = $click;
        //判断是不是地雷
        if ($board[$row][$col] == 'M' || $board[$row][$col] == 'X') {
            $board[$row][$col] = 'X';
        } else {
            //不是地雷， 计算周围是地雷的个数
            $count = 0;
            foreach([-1, 0, 1] as $i) {
                foreach([-1, 0, 1] as $j) {
                    if ($i == 0 && $j == 0) continue;
                    $r = $row + $i;
                    $c = $col + $j;
                    if ($r < 0 || $c < 0 || $r >= $n || $c >= $m) continue;
                    if ($board[$r][$c] == 'M' || $board[$r][$c] == 'X') $count++;
                }
            }
            //有地雷，标注地雷的个数
            if ($count > 0) {
                $board[$row][$col] = (string)$count;
            } else {
                //没有地雷，标注为B
                $board[$row][$col] = 'B';
                foreach([-1, 0, 1] as $i) {
                    foreach([-1, 0, 1] as $j) {
                        if ($i == 0 && $j == 0) continue;
                        $r = $row + $i;
                        $c = $col + $j;
                        if ($r < 0 || $c < 0 || $r >= $n || $c >= $m) continue;
                        if ($board[$r][$c] == 'E') $this->dfs($board, [$r, $c], $n, $m);
                    }
                }
            }
        }
    }
    
    /**
     * bfs
     * @param String[][] $board
     * @param Integer[] $click
     * @return String[][]
     */
    function updateBoard($board, $click) {
        $n = count($board);
        $m = count($board[0]);
        $queue = [$click];
        while ($queue) {
            [$row, $col] = array_shift($queue);
            //地雷
            if ($board[$row][$col] == 'M' || $board[$row][$col] == 'X') {
                $board[$row][$col] = 'X';
            } else {
                //计算周围的地雷
                $count = 0;
                foreach([-1, 0, 1] as $i) {
                    foreach([-1, 0, 1] as $j) {
                        if ($i == 0 && $j == 0) continue;
                        $r = $row + $i;
                        $c = $col + $j;
                        if ($r < 0 || $c < 0 || $r >= $n || $c >= $m) continue;
                        if ($board[$r][$c] == 'M' || $board[$r][$c] == 'X') $count++;
                    }
                }
                //有地雷，标注地雷的个数
                if ($count > 0) {
                    $board[$row][$col] = (string)$count;
                } else {
                    //没有地雷，标注为B
                    $board[$row][$col] = 'B';
                    foreach([-1, 0, 1] as $i) {
                        foreach([-1, 0, 1] as $j) {
                            if ($i == 0 && $j == 0) continue;
                            $r = $row + $i;
                            $c = $col + $j;
                            if ($r < 0 || $c < 0 || $r >= $n || $c >= $m) continue;
                            if ($board[$r][$c] == 'E') {
                                $queue[] = [$r, $c];
                                $board[$r][$c] = 'B';
                            }
                        }
                    }
                }
            }
        }
        return $board;
    }
}
```