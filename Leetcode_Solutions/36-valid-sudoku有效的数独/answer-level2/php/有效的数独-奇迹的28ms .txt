### 解题思路
         * 第步：行判断
         * 第二步：列判断
         * 第三步：区域判断
         * 区域判断9个重要点
         * 第一区域$board[1][1]
         * 第二区域$board[1][4]
         * 第三区域$board[1][7]
         * 第四区域$board[4][1]
         * 第五区域$board[4][4]
         * 第六区域$board[4][7]
         * 第七区域$board[7][1]
         * 第八区域$board[7][4]
         * 第九区域$board[7][7]

### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @return Boolean
     */
    function isValidSudoku($board) {
        //行判断
        for ($i = 0; $i < count($board); $i++) {
            $arrh = array_count_values($board[$i]);
            foreach ($arrh as $key => $value) {
                if ($key != '.' && $value >1) {
                    return false;
                }
            }
        }
        //列判断
        $arrl= array();
        for ($j = 0; $j < count($board); $j++) {
            for ($k = 0; $k < count($board); $k++) {
                $arrl[$j][$k] = $board[$k][$j];
            }            
        }
        for ($w = 0; $w < count($arrl); $w++) {
            $arrpl= array_count_values($arrl[$w]);
            foreach ($arrpl as $key => $value) {
                if ($key != '.' && $value >1) {
                    return false;
                }
            }
        }
        //区域判断
        $arrq = array();
        for ($l = 1; $l < count($board)-1; $l=$l+3) {
            for ($m = 1; $m < count($board)-1; $m=$m+3) {
                $arrq[] = [
                    $board[$l-1][$m-1],
                    $board[$l-1][$m],
                    $board[$l-1][$m+1],
                    $board[$l][$m-1],
                    $board[$l][$m],
                    $board[$l][$m+1],
                    $board[$l+1][$m-1],
                    $board[$l+1][$m],
                    $board[$l+1][$m+1]
                ];
            }
        }
        for ($n = 0; $n < count($arrq); $n++) {
            $arrpq= array_count_values($arrq[$n]);
            foreach ($arrpq as $key => $value) {
                if ($key != '.' && $value >1) {
                    return false;
                }
            }
        }
        return true;
    }
}
```