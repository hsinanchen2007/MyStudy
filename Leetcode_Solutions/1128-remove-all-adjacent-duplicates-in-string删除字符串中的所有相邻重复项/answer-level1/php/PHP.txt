时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function removeDuplicates($S) {
        $array = [];
        $num = 0;

        for ($i = 0, $length = strlen($S); $i < $length; $i++) {
            if (isset($array[$num]) && $array[$num] == $S[$i]) {
                unset($array[$num--]);
            } else {
                $array[++$num] = $S[$i];
            }
        }

        $s = '';

        for ($i = 1, $count = count($array); $i <= $count; $i++) {
            $s .= $array[$i];
        }

        return $s;
    }
}
```