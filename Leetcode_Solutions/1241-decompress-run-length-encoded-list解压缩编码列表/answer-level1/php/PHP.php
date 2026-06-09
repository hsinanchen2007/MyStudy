时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function decompressRLElist($nums) {
        $array = [];

        for ($i = 0, $j = 1, $count = count($nums); $i < $count; $i += 2, $j+= 2) {
            while ($nums[$i]) {
                $array[] = $nums[$j];
                $nums[$i]--;
            }
        }

        return $array;
    }
}
```