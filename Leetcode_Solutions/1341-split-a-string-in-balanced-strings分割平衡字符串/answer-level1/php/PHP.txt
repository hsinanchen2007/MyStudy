时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function balancedStringSplit($s) {
        $count = 0;
        $num = 0;

        for ($i = 0, $length = strlen($s); $i < $length; $i++) {
            $s[$i] == 'R' ? $count++ : $count--;
            if ($count == 0) {
                $num++;
            }
        }

        return $num;
    }
}
```