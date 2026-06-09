时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findNumbers($nums) {
        $num = 0;

        for ($i = 0, $count = count($nums); $i < $count; $i++) {
            $length = 0;
            while ($nums[$i]) {
                $nums[$i] = (int) ($nums[$i] / 10);
                $length++;
            }
            $length & 1 ?: $num++;
        }

        return $num;
    }
}
```