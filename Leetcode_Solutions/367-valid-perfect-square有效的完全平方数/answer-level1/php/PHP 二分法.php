```php
class Solution
{
    /**
     * @param Integer $num
     * @return Boolean
     */
    function isPerfectSquare($num)
    {
        if ($num == 1) {
            return true;
        }
        // 二分查找 注意边界
        $l = 1;
        $r = $num;
        while ($l < $r) {
            $mid = $l + floor((($r - $l) / 2));
            if ($mid * $mid == $num) {
                return true;
            } elseif ($mid * $mid < $num) {
                $l = $mid + 1;
            } else {
                $r = $mid - 1;
            }
        }
        return $l * $l == $num;
    }
}
```
