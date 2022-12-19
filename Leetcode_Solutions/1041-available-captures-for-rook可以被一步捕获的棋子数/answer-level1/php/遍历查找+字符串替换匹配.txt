### 解题思路
执行用时 :4 ms , 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了100.00%的用户

在[https://leetcode-cn.com/problems/available-captures-for-rook/solution/bian-li-php-by-salmonl-7/](仁兄)的基础上加了一行代码
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

        $count = 0;
        if (strpos($row, 'Rp') !== false) $count++;
        if (strpos($row, 'pR') !== false) $count++;
        if (strpos($col, 'Rp') !== false) $count++;
        if (strpos($col, 'pR') !== false) $count++;

        /*
        作者：salmonl
链接：https://leetcode-cn.com/problems/available-captures-for-rook/solution/bian-li-php-by-salmonl-7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
        return $count;
    }
}
```