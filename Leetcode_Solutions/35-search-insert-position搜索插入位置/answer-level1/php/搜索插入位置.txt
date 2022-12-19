### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
    $left  = 0;
    $right = count($nums) - 1;
    while ($left <= $right) {
        $mid = (int)(($left + $right) / 2);
        if ($nums[$mid] === $target) {
            return $mid;
        }
        if ($nums[$mid] < $target) {
            $left = $mid + 1;
        } else {
            $right = $mid - 1;
        }
    }
    return $left;
    }
}
```

执行用时 :8 ms, 在所有 PHP 提交中击败了99.04%的用户
内存消耗 :15.6 MB, 在所有 PHP 提交中击败了75.61%的用户
