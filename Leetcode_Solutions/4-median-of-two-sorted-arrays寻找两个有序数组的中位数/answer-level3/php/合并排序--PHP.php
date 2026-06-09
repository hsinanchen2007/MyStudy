### 解题思路
合并两个数组，排序，然后找中位数

### 性能
执行用时 :44 ms, 在所有 PHP 提交中击败了38.27%的用户
内存消耗 :15.3 MB 在所有 PHP 提交中击败了5.12%的用户

### 代码

```php
/**
 * 简单式：
 * - 支持 $nums1, $nums2 为无序数组
 */
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Float
     */
    function findMedianSortedArrays(array $nums1, array $nums2): float
    {
        $nums = array_merge($nums1, $nums2);
        sort($nums);

        $n = count($nums);
        $i = $n - 1;
        if ($n % 2 == 0) { //偶数
            $m = ($nums[$i / 2] + $nums[$i / 2 + 1]) / 2;
        } else {
            $m = $nums[($i + 1) / 2];
        }

        return $m;
    }
}
```