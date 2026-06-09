时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $candies
     * @return Integer
     */
    function distributeCandies($candies) {
        $hash = [];

        for ($i = 0, $count = count($candies), $num1 = 0, $num2 = $count / 2; $i < $count; $i++) {
            if (!isset($hash[$candies[$i]])) {
                $hash[$candies[$i]] = '';
                $num1++;
            }
        }

        return $num1 < $num2 ? $num1 : $num2;
    }
}
```