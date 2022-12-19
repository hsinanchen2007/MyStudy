时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[][] $points
     * @return Integer
     */
    function minTimeToVisitAllPoints($points) {
        $time = 0;

        for ($i = 0, $count = count($points) - 1; $i < $count; $i++) {
            $x = $points[$i][0] - $points[$i + 1][0];
            $x >= 0 ?: $x *= -1;
            $y = $points[$i][1] - $points[$i + 1][1];
            $y >= 0 ?: $y *= -1;
            $time += $x > $y ? $x : $y;
        }

        return $time;
    }
}
```