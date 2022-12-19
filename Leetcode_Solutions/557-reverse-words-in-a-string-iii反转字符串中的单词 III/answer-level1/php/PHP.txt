时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $string = '';
        $S = '';

        for ($i = 0, $length = strlen($s); $i < $length; $i++) {
            if ($s[$i] == ' ' || $end = $i == $length - 1) {
                if ($end) {
                    $string .= $s[$i];
                }
                for ($l = 0, $len = strlen($string), $r = $len - 1; $l < $r; $l++, $r--) {
                    $tmp = $string[$l];
                    $string[$l] = $string[$r];
                    $string[$r] = $tmp;
                }
                $S .= $string;
                if ($s[$i] == ' ') {
                    $S .= ' ';
                }
                $string = '';
            } else {
                $string .= $s[$i];
            }
        }

        return $S;
    }
}
```