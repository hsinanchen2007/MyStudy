PHP  二分解法，注意边界的处理

```php
class Solution
{

    /**
     * @param Integer $x
     * @return Integer
     */
    function mySqrt($x)
    {
        if ($x <= 1) {
            return $x;
        }
        $l = 1;
        $r = floor($x / 2) + 1;
        while ($l < $r) {
            // 取右中位数，否则会死循环
            $mid = $l + floor(($r - $l + 1) / 2);
            if ($mid * $mid == $x) {
                return $mid;
            } elseif ($mid * $mid < $x) {
                $l = $mid;
            } else {
                $r = $mid - 1;
            }
        }

        return $l;
    }
}
```
