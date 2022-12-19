### 解题思路
思路不难，但是题出的有歧义，一次移动刚开始以为只能选一个方向，看过官方解才知道四个方向都可以走且都走完才算是一次移动-_-

### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @return Integer
     */
    function numRookCaptures($board) {
        // 定义上下左右四个方向
        $dx = [-1, 1, 0, 0];
        $dy = [0, 0, -1, 1];
       
        for ($i = 0; $i < 8; $i++) {
            for ($j = 0; $j < 8; $j++) {
                // 找到白车所在的位置
                if ($board[$i][$j] == 'R') {
                    // 分别判断白车的上、下、左、右四个方向
                    $captures = 0;
                    for ($d = 0; $d < 4; $d++) {
                        $x = $i;
                        $y = $j;
                        while (true) {
                            $x += $dx[$d];//当前位置x坐标
                            $y += $dy[$d];//当前位置y坐标

                            //如果当前坐标出界或者遇到象则退出循环，尝试下一方向
                            if ($x < 0 || $x >= 8 || $y < 0 || $y >= 8 || $board[$x][$y] == 'B') {
                                break;
                            }
                            //如遇到不同色卒子则吃掉，退出循环（一个方向最多吃一个卒子），尝试下一方向
                            if ($board[$x][$y] == 'p') {
                                $captures++;
                                break;
                            }
                        }
                    }
                    return $captures;
                }
            }
        }
    }
}
```