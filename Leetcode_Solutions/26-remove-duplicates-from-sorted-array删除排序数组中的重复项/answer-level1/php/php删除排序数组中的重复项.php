
用双指针算法,用两个游标n,m,逐个比较


```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $count = count($nums);
        if ($count == 0) return 0;
        $n = 0;
        $m = 1;
        while ($m < $count) {
            if ($nums[$n] != $nums[$m]) {
                $n++;
                $nums[$n] = $nums[$m];
            }
            $m++;
        }
        return $n + 1;
    }
}
```
