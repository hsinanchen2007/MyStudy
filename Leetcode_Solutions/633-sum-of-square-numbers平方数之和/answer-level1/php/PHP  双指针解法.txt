注意两种特殊情况，
1. a=0 即 c 是完全平方数也可以
2. a=b 也可以


```php
class Solution
{
    /**
     * @param Integer $c
     * @return Boolean
     */
    function judgeSquareSum($c)
    {
        // double pointer
        $l = 0;
        $r = floor(sqrt($c));
        while ($l <= $r) {
            if ($c - $l * $l == $r * $r) {
                return true;
            } elseif ($c - $l * $l < $r * $r) {
                $r--;
            } else {
                $l++;
            }
        }

        return false;
    }
}
```
