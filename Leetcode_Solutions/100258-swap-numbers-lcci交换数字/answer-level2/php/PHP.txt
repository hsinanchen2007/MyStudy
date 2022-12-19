时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $numbers
     * @return Integer[]
     */
    function swapNumbers($numbers) {
        $numbers[0] = $numbers[0] - $numbers[1];
        $numbers[1] = $numbers[1] + $numbers[0];
        $numbers[0] = $numbers[1] - $numbers[0];

        return $numbers;
    }
}
```