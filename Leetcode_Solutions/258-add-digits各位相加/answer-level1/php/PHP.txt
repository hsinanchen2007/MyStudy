时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function addDigits($num) {
        if ($num < 10) {
            return $num;
        }

        $mod = $num % 9;

        return $mod == 0 ? 9 : $mod;
    }
}
```