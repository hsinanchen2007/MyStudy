时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function orangesRotting($grid) {
        $array = [];

        foreach ($grid as $key => $value) {
            foreach ($value as $k => $v) {
                if ($v == 2) {
                    $array[] = [$key, $k];
                }
            }
        }

        $num = 0;

        while (!empty($array)) {
            foreach ($array as $key => $value) {
                $row = $value[0];
                $col = $value[1];
                $top = $row - 1;
                if (isset($grid[$top][$col]) && $grid[$top][$col] == 1) {
                    $grid[$top][$col] = 2;
                    $array[] = [$top, $col];
                }
                $right = $col + 1;
                if (isset($grid[$row][$right]) && $grid[$row][$right] == 1) {
                    $grid[$row][$right] = 2;
                    $array[] = [$row, $right];
                }
                $bottom = $row + 1;
                if (isset($grid[$bottom][$col]) && $grid[$bottom][$col] == 1) {
                    $grid[$bottom][$col] = 2;
                    $array[] = [$bottom, $col];
                }
                $left = $col - 1;
                if (isset($grid[$row][$left]) && $grid[$row][$left] == 1) {
                    $grid[$row][$left] = 2;
                    $array[] = [$row, $left];
                }
                unset($array[$key]);
            }
            $num++;
        }

        foreach ($grid as $value) {
            foreach ($value as $v) {
                if ($v == 1) {
                    return -1;
                }
            }
        }

        return $num == 0 ? $num : $num - 1;
    }
}
```