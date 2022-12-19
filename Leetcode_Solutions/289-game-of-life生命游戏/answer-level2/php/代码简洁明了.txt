### 解题思路
在所有 PHP 提交中击败了 100.00%
的用户嵌套循环，分别得到当前元素的 “周围8个”值。由于是1和0组合，那么采用加法即可得到1的个数，效率比较高一点。


### 代码

```php
class Solution {

    /**
     * @param Integer[][] $board
     * @return NULL
     */
    function gameOfLife(&$board) {
        $rowLen = count($board);
        $colLen = count($board[0]);

        $data = $board;
        for ($i = 0; $i < $rowLen; $i++) {
            for ($j = 0; $j < $colLen; $j++) {
                // print_r($data[$i][$j]);
                // echo ',';
                $ltop = isset($data[$i - 1][$j - 1]) ? $data[$i - 1][$j - 1] : 0;
                $top = isset($data[$i - 1][$j]) ? $data[$i - 1][$j] : 0;
                $rtop = isset($data[$i - 1][$j + 1]) ? $data[$i - 1][$j + 1] : 0;
                $left = isset($data[$i][$j - 1]) ? $data[$i][$j - 1] : 0;
               
                $self = $data[$i][$j];
                $right = isset($data[$i][$j + 1]) ? $data[$i][$j + 1] : 0;
                $lbottom = isset($data[$i + 1][$j - 1]) ? $data[$i + 1][$j - 1] : 0;
                $bottom = isset($data[$i + 1][$j]) ? $data[$i + 1][$j] : 0;
                $rbottom = isset($data[$i + 1][$j + 1]) ? $data[$i + 1][$j + 1] : 0;

                // if self=1 && count(1)<2 =>self=0
                // if self=1 && count(1) in 2,3 =>self=1
                // if self=1 && count(1)>3 =>self=0
                // if self=0 && count(1)=3 =>self=1
                $_count = $ltop + $top + $rtop + $left+ $right + $lbottom + $bottom + $rbottom;
                // echo "$i,$j, = $self, $_count, [$ltop + $top + $rtop + $right + $lbottom + $bottom + $rbottom]" . PHP_EOL;
                if ($self == 0) {
                    if ($_count == 3) {
                        // 条件4:复活
                        $board[$i][$j] = 1;
                    }
                } else if ($_count < 2) {
                    // 条件1:死亡
                    $board[$i][$j] = 0;
                } else if ($_count > 3) {
                    // 条件3:死亡
                    $board[$i][$j] = 0;
                }
                // else {
                //     // 条件2:任然存活
                // }
            }
        }

        return $board;
    }
}
```