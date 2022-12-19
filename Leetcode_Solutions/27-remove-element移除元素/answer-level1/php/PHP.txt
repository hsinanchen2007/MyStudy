时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        $num = 0;

        for ($i = 0, $count = count($nums); $i < $count; $i++) {
            if ($nums[$i] == $val) {
                unset($nums[$i]);
            } else {
                $num++;
            }
        }

        return $num;
    }
}
```