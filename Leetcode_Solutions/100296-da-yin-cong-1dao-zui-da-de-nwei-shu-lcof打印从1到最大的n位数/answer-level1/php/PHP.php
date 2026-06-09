时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer[]
     */
    function printNumbers($n) {
        $nums = [];

        for ($i = 1, $num = 10 ** $n; $i < $num; $i++) {
            $nums[] = $i;
        }

        return $nums;
    }
}
```