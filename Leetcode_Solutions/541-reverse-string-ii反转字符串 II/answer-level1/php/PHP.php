时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $k
     * @return String
     */
    function reverseStr($s, $k) {
        for ($i = 0, $length = strlen($s); $i < $length; $i += 2 * $k) {
            $l = $i;
            $r = $l + $k - 1;
            $s[$r] ?? $r = $length - 1;
            while ($l < $r) {
                $tmp = $s[$l];
                $s[$l] = $s[$r];
                $s[$r] = $tmp;
                $l++;
                $r--;
            }
        }

        return $s;
    }
}
```