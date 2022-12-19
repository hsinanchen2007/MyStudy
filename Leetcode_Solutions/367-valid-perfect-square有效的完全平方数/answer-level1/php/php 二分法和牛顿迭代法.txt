```php
class Solution {

    /**
     * 方法一：二分法
     * @param Integer $num
     * @return Boolean
     */
    function isPerfectSquare($num) {
        if ($num < 2) return true;
        $left = 1;
        $right = intdiv($num, 2);
        while ($left <= $right) {
            $mid = $left + intdiv($right - $left, 2);
            $n = $mid * $mid;
            if ($n > $num) $right = $mid - 1;
            else if ($n < $num) $left = $mid + 1;
            else return true;
        }
        return false;
    }
     /**
     * 方法二：牛顿迭代法
     * @param Integer $num
     * @return Boolean
     */
    function isPerfectSquare($num) {
        if ($num < 2) return true;
        $curr = intdiv($num, 2);
        while ($curr * $curr > $num) {
            $curr = intdiv($curr + $num / $curr, 2);
        }
        return $curr * $curr == $num;
    }
}
```
