### 解题思路
前半部分代码学习前辈的，最后一句利用PHP弱语言特性，节省空间

### 代码

```php
class Solution {
    /**
     * @param String[][] $board
     * @return Integer
     */
    function numRookCaptures($board) {
        $row_R = $col_R = 0;
        for($i=0; $i<8; $i++) {
            for($j=0;$j<8;$j++) {
                if($board[$i][$j] == "R"){
                   $row_R = $i;
                   $col_R = $j; 
                   break 2;
                }
            }
        }

        $row = str_replace('.', '', implode('', $board[$row_R]));
        $col = str_replace('.', '', implode('', array_column($board, $col_R)));

        return (strpos($row,'Rp')!==false) + (strpos($row,'pR')!==false) + (strpos($col,'Rp')!==false)+ (strpos($col,'pR')!==false);
    }
    
}
```