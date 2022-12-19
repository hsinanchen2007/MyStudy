时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer[]
     */
    function countBits($num) {
        $array = [0];

        for ($i = 1; $i <= $num; $i++) {
            $array[$i] = $array[$i & ($i - 1)] + 1;
        }

        return $array;
    }
}
```