### 解题思路
严格按照题目往下走

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {

        $final = $board;

        for ($i = 0; $i < count($board); $i++) {
            for ($j = 0; $j < count($board[$i]); $j++) {
                //检查周围情况，返回四周的活点
                $surroundings = $this->determine($i , $j , $board);

                //如果当前点是活点
                if ($board[$i][$j] == 1) {     
                    if ($surroundings == 2 || $surroundings == 3) {
                        $final[$i][$j] = 1;
                    } else {
                        $final[$i][$j] = 0;
                    }
                } else {
                    if ($surroundings == 3) {
                        $final[$i][$j] = 1;
                    } else {
                        $final[$i][$j] = 0;
                    }
                }

            }

        }
        $board = $final;
    }

    public function determine($x , $y , $board) {
        $living_dots = 0;

        if ($board[$x - 1][$y - 1] == 1) {//左下
            $living_dots++;
        }
        if ($board[$x - 1][$y] == 1) {//左边
            $living_dots++;
        }
        if ($board[$x - 1][$y + 1] == 1) {//左上
            $living_dots++;
        }
        if ($board[$x][$y + 1] == 1) {//正上
            $living_dots++;
        }
        if ($board[$x + 1][$y + 1] == 1) {//右上
            $living_dots++;
        }
        if ($board[$x + 1][$y] == 1) {//右边
            $living_dots++;
        }
        if ($board[$x + 1][$y - 1] == 1) {//右下
            $living_dots++;
        }
        if ($board[$x][$y - 1] == 1) {//正下
            $living_dots++;
        }
        
        return $living_dots;
    }
}
```