```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate1(&$matrix) {
        $tmp = $matrix;
        $n = count($matrix);
        for($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $n; $j++) {
                $matrix[$j][$n - $i - 1] = $tmp[$i][$j];
            }
        }
    }
    function rotate2(&$matrix) {
        $n = count($matrix);
        for($i = 0; $i < floor($n / 2); $i++) {
            for ($j = 0; $j < floor(($n + 1) / 2); $j++) {
                $tmp = $matrix[$i][$j];
                $matrix[$i][$j] = $matrix[$n - $j - 1][$i];
                $matrix[$n - $j - 1][$i] = $matrix[$n - $i - 1][$n - $j - 1];
                $matrix[$n - $i - 1][$n - $j - 1] = $matrix[$j][$n - $i - 1];
                $matrix[$j][$n - $i - 1] = $tmp;
            }
        }
    }
    function rotate(&$matrix) {
        $n = count($matrix);
        for($i = 0; $i < floor($n / 2); $i++) {
            for ($j = 0; $j < $n; $j++) {
               [$matrix[$i][$j], $matrix[$n - $i - 1][$j]] = [$matrix[$n - $i - 1][$j], $matrix[$i][$j]];
            }
        }
        for($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $i; $j++) {
               [$matrix[$i][$j], $matrix[$j][$i]] = [$matrix[$j][$i], $matrix[$i][$j]];
            }
        }
    }
}
```
