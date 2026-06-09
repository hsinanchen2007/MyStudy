### 解题思路
执行用时 :0 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.6 MB, 在所有 PHP 提交中击败了100.00%的用户

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
        unset($board);
        return (strpos($row,'Rp')!==false) + (strpos($row,'pR')!==false) + (strpos($col,'Rp')!==false)+ (strpos($col,'pR')!==false);
    }
    
}
```