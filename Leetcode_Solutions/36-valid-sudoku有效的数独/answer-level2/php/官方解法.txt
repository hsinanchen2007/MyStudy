### 解题思路
官方思路
### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @return Boolean
     */
    function isValidSudoku($board) {
        $row = [];
        $col = [];
        $box = [];
        for($i=0;$i<9;$i++){
            for($j=0;$j<9;$j++){
                if($board[$i][$j]!='.'){
                    $n = $board[$i][$j];//current number
                    $row[$i][$n] = isset($row[$i][$n])?$row[$i][$n]+1:1;//current number in current row
                    $col[$j][$n] = isset($col[$j][$n])?$col[$j][$n]+1:1;//current number in current col
                    $box_index = floor($i / 3) * 3 + floor($j / 3);//current block index
                    $box[$box_index][$n] = isset($box[$box_index])?$box[$box_index][$n]+1:1;
                    if($row[$i][$n]>1 || $col[$j][$n]>1 || $box[$box_index][$n]>1){
                        return false;
                    }
                }
            }
        }
        return true;


    }
}
```