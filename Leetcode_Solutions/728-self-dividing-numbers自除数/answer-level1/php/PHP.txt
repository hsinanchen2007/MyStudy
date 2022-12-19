时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $left
     * @param Integer $right
     * @return Integer[]
     */
    function selfDividingNumbers($left, $right) {
        $array = [];

        for ($num = $left; $left <= $right; $num = ++$left) {
            while ($num) {
                $mod = $num % 10;
                if ($mod == 0 || $left % $mod != 0) {
                    continue 2;
                }
                $num = (int) ($num / 10);
            }
            $array[] = $left;
        }

        return $array;
    }
}
```