### 解题思路
二分法，不是特别好理解。写写个人的理解。

- 旋转排序数组后，我们以任何一元素下标作为分界点，把数组一分为二，始终有一个是有序的。既然选那个都行，当然选中间的那个是最高效的了。
- 如果中间元素小于最右端的元素，那么右半部分是有序的，检查target是否在右半部分，如果在就是常规的二分查找，如果不在，就进入左半部分，继续一分二位查找。【中间元素和最左端的元素比也可以】
- 如果中间元素不小于最右端的元素，那么同理。

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了24.05%的用户
内存消耗 :15.4 MB, 在所有 PHP 提交中击败了18.46%的用户

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

            if ($nums[$mid] == $target) return $mid;

            if ($nums[$mid] < $nums[$rear]) {
                if ($nums[$mid] < $target && $target <= $nums[$rear]) {
                    $front = $mid + 1;
                } else {
                    $rear = $mid - 1;
                }
            } else {
                if ($nums[$mid] > $target && $target >= $nums[$front]) {
                    $rear = $mid - 1;
                } else {
                    $front = $mid + 1;
                }                
            }
        }

        return -1;
    }
}
```

### 算法复杂度
- 时间复杂度 O（logn）
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/search-in-rotated-sorted-array/comments/990](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/comments/990)
[https://leetcode-cn.com/problems/search-in-rotated-sorted-array/comments/114623](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/comments/114623)