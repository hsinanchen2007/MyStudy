时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $n
     * @param Integer $m
     * @param Integer[][] $indices
     * @return Integer
     */
    function oddCells($n, $m, $indices) {
        $array = [];

        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $m; $j++) {
                $array[$i][] = 0;
            }
        }

        foreach ($indices as $indice) {
            foreach ($array[$indice[0]] as &$value) {
                $value++;
            }
            unset($value);
            foreach ($array as &$value) {
                $value[$indice[1]]++;
            }
            unset($value);
        }

        $num = 0;

        foreach ($array as $value) {
            foreach ($value as $v) {
                if ($v & 1) {
                    $num++;
                }
            }
        }

        return $num;
    }
}
```