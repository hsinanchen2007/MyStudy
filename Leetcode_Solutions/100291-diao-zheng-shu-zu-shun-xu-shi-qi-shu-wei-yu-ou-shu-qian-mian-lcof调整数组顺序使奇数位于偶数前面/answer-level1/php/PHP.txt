时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function exchange($nums) {
        $l = 0;
        $r = count($nums) - 1;

        while ($l < $r) {
            if ($nums[$l] & 1) {
                $l++;
                continue;
            }
            if (!($nums[$r] & 1)) {
                $r--;
                continue;
            }
            $tmp = $nums[$l];
            $nums[$l] = $nums[$r];
            $nums[$r] = $tmp;
            $l++;
            $r--;
        }

        return $nums;
    }
}
```