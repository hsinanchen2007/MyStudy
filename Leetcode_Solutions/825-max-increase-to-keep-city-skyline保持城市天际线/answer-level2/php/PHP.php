时间复杂度： O(n^2)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxIncreaseKeepingSkyline($grid) {
        $row = [];
        $num1 = 0;

        foreach ($grid as $key => $value) {
            $row[$key] = 0;
            foreach ($value as $v) {
                $row[$key] > $v ?: $row[$key] = $v;
                $num1 += $v;
            }
        }

        $column = [];

        foreach ($grid[0] as $key => $value) {
            $column[$key] = 0;
            foreach ($grid as $v) {
                $column[$key] > $v[$key] ?: $column[$key] = $v[$key];
            }
        }

        $num2 = 0;

        foreach ($grid as $key => &$value) {
            foreach ($value as $k => &$v) {
                $v = $row[$key] < $column[$k] ? $row[$key] : $column[$k];
                $num2 += $v;
            }
        }

        return $num2 - $num1;
    }
}
```