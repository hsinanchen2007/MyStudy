### 解题思路

### 性能
执行用时 :96 ms, 在所有 php 提交中击败了30.00%的用户
内存消耗 :16.2 MB, 在所有 php 提交中击败了6.45%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        $front = 0;
        $rear = count($nums) - 1;
        while ($front <= $rear) {
            $mid = intval(($front + $rear) / 2);
            if ($nums[$mid] > $target) {
                $rear = $mid - 1; 
            } elseif ($nums[$mid] < $target) {
                $front = $mid + 1;
            } else {
                return $mid;
            }
        }

        return -1;
    }
}
```