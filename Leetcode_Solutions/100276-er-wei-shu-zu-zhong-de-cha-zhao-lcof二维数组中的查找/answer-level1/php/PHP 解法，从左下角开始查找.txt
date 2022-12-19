### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @param Integer $target
     * @return Boolean
     */
    function findNumberIn2DArray($matrix, $target) {
        $row = count($matrix);
        if ($row == 0) return false;
        $col = count($matrix[0]);
        if ($col == 0) return false;
        // 从左下角开始查找
        $x = $row - 1;
        $y = 0;
        while ($x >= 0 && $y <= $col - 1) {
            if ($target < $matrix[$x][$y]) {
                $x--;
            } elseif ($target > $matrix[$x][$y]) {
                $y++;
            } else {
                return true;
            }
        }

        return false;
    }
}
```