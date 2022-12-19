
```
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        if (!is_int($x)) return 0;
        $res = 0;
        $max = pow(2, 31) - 1;
        $min = pow(-2, 31);
        while ($x >= 10 || $x <= -10) {
            $remainder = $x % 10;
            $x = ($x - $remainder) / 10;
            $res = $res * 10 + $remainder;
        }
        if (($res > ($max - 7) / 10) || ($res === ($max - 7) / 10 && $x > 7)) return 0;
        if ($res < ($min + 8) / 10 || ($res === ($min + 8) / 10 && $x < -8)) return 0;
        return $res * 10 + $x;
    }
}
```