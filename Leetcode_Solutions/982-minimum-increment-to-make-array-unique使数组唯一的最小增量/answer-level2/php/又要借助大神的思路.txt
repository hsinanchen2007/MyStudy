### 解题思路
感谢[@sweetiee](/u/sweetiee/)的解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($A) {
        sort($A);
        $steps = 0;
        for ($i = 1; $i < count($A); $i++) {
            if ($A[$i] <= $A[$i - 1]) {
                // echo "$i: " . $A[$i] . " >>> " . $A[$i-1] . "\n";
                $pre = $A[$i];
                $A[$i] = $A[$i - 1] + 1;
                $steps += $A[$i] - $pre;
                // print_r($A);
            }
        }
        return $steps;
    }
}
```