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

        $list = $board;
        $len = count($board);
        for ($i = 0; $i < $len; $i++) {

            for ($j = 0; $j < count($board[$i]); $j++) {
                if ($board[$i][$j] == 1) {
                    //活细胞条件
                    $back = $this->help($i , $j , $board);
                    if ($back == 2 || $back == 3) {

                        $list[$i][$j] = 1;
                    } else {
                        $list[$i][$j] = 0;
                    }
                } else {
                    //死细胞条件
                    $back = $this->help($i , $j , $board);

                    if ($back == 3) {
                        $list[$i][$j] = 1;
                    } else {
                        $list[$i][$j] = 0;
                    }
                }

            }

        }
        $board = $list;
    }

    public function help ($x , $y , $board) {
        $times = 0;
        if (isset($board[$x - 1][$y - 1])) {
            $board[$x - 1][$y - 1] == 1 ? $times++ : '';
        }
        if (isset($board[$x - 1][$y])) {
            $board[$x - 1][$y] == 1 ? $times++ : '';
        }
        if (isset($board[$x - 1][$y + 1])) {
            $board[$x - 1][$y + 1] == 1 ? $times++ : '';
        }

        if (isset($board[$x][$y - 1])) {
            $board[$x][$y - 1] == 1 ? $times++ : '';
        }
        if (isset($board[$x][$y + 1])) {
            $board[$x][$y + 1] == 1 ? $times++ : '';
        }

        if (isset($board[$x + 1][$y - 1])) {
            $board[$x + 1][$y - 1] == 1 ? $times++ : '';
        }
        if (isset($board[$x + 1][$y])) {
            $board[$x + 1][$y] == 1 ? $times++ : '';
        }
        if (isset($board[$x + 1][$y + 1])) {
            $board[$x + 1][$y + 1] == 1 ? $times++ : '';
        }
        return $times;
    }
}
```