时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $S
     * @param String $C
     * @return Integer[]
     */
    function shortestToChar($S, $C) {
        $length = strlen($S);
        $array = [];

        for ($i = 0; $i < $length; $i++) {
            if ($S[$i] == $C) {
                $p = $i;
            }
            $array[$i] = isset($p) ? $i - $p : '';
        }

        unset($p);

        for ($i = $length - 1; $i >= 0; $i--) {
            if ($S[$i] == $C) {
                $p = $i;
            }
            if (!isset($p)) {
                continue;
            }
            $tmp = $p - $i;
            if ($array[$i] === '' || $tmp < $array[$i]) {
                $array[$i] = $tmp;
            }
        }

        return $array;
    }
}
```