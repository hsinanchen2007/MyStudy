时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function singleNumber($nums) {
        $tmp = 0;

        foreach ($nums as $value) {
            $tmp ^= $value;
        }

        $diff = $tmp & -$tmp;
        $num = 0;

        foreach ($nums as $value) {
            if ($diff & $value) {
                $num ^= $value;
            }
        }

        return [$num, $tmp ^ $num];
    }
}
```