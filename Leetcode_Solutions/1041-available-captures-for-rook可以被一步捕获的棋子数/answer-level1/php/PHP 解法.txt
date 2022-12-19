按题目意思写就可以了

```php
class Solution {

    /**
     * @param String[][] $board
     * @return Integer
     */
    function numRookCaptures($board) {
        for ($row = 0; $row < 8; ++$row) {
            for ($col = 0; $col < 8; ++$col) {
                if ($board[$row][$col] == 'R') break 2;
            }
        }

        $count = 0;
        if ($col > 0) {
            for ($j = $col - 1; $j >= 0; --$j) {
                if ($board[$row][$j] == 'B') break;
                if ($board[$row][$j] == 'p') {
                    $count++;
                    break;
                }
            }
        } 

        if ($col < 7) {
            for ($j = $col + 1; $j < 8; ++$j) {
                if ($board[$row][$j] == 'B') break;
                if ($board[$row][$j] == 'p') {
                    $count++;
                    break;
                }
            }
        }  

        if ($row > 0) {
            for ($i = $row - 1; $i > 0; --$i) {
                if ($board[$i][$col] == 'B') break;
                if ($board[$i][$col] == 'p') {
                    $count++;
                    break;
                }
            }
        } 

        if ($row < 7) {
            for ($i = $row + 1; $i < 8; ++$i) {
                if ($board[$i][$col] == 'B') break;
                if ($board[$i][$col] == 'p') {
                    $count++;
                    break;
                }
            }
        } 

        
        return $count;
    }
}
```