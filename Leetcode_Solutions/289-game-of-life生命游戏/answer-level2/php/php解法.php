### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {
        if(empty($board)) {
            return [];
        }
        $rows = count($board);
        $cols = count($board[0]);
        $cpBoard = $board;
        for ($i = 0; $i < $rows; $i++) {
            for ($j = 0; $j < $cols; $j++) {
                $arr = [];
                for ($a = $i - 1; $a <= $i + 1; $a++) {
                    for ($b = $j - 1; $b <= $j + 1; $b++) {
                        if (($i != $a || $j != $b) && isset($cpBoard[$a][$b])) {
                            if (isset($arr[$cpBoard[$a][$b]])) {
                                $arr[$cpBoard[$a][$b]] += 1;
                            } else {
                                $arr[$cpBoard[$a][$b]] = 1;
                            }
                        }
                    }
                }
                if ($board[$i][$j] == 0) {
                    if (isset($arr[1]) && $arr[1] == 3) {
                        $board[$i][$j] = 1;
                    }
                } else {
                    if (!isset($arr[1]) || $arr[1] < 2 || $arr[1] > 3) {
                        $board[$i][$j] = 0;
                    }
                }
            }
        }
    }
}
```