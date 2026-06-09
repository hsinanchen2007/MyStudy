时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $target
     * @return Integer[][]
     */
    function findContinuousSequence($target) {
        $nums = [];

        for ($i = 1; $i < $target / 2; $i++) {
            $sum = $i;
            $tmp = [$i];
            for ($j = $i + 1; $j < $target; $j++) {
                $sum += $j;
                $tmp[] = $j;
                if ($sum == $target) {
                    $nums[] = $tmp;
                    break;
                }
                if ($sum > $target) {
                    break;
                }
            }
        }

        return $nums;
    }
}
```