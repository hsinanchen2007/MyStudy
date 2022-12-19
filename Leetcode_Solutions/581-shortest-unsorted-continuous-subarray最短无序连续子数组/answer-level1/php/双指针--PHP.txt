### 解题思路
简单来说就是找数组中最短的一段无序数组。**这类题对思维锻炼是极好的题，选择最优的解，你会收获很多。**

一遍思路：
最容易想到的思路：排序，然后双指针头尾比对差异值，记录下标，计算长度。可参考[这里](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/comments/94926)。

更优的解决方案：
遍历数组，从左找小于数组中最大元素max的元素，记录最后一个小于最大元素的下标high；同理从右找大于数组中最小元素min的元素，记录最后一个大于最大元素的下标low。如果low >= high, 说明数组本身有序，否则high - low + 1就是无序号长度。

算法：
**1. 初始设定数组中最大值为第一个元素，最小值为最后一个元素，即$max = $nums[0]; $min = $nums[count($nums) - 1];
2. 设定无序子数组的起始下标为low，log = count($nums) - 1, 截止下标为high, high = 0。
3. 从第二个元素开始遍历数组。
4. 从左往右，如果当前元素大于max, 就更新max为当前元素，然后检查当前元素，如果比max小, 就把当前元素下标赋值给high;
5. 从右往左，如果当前元素小于min, 就更新min为当前元素，然后检查当前元素，如果比min大，就把当前元素下标赋值给low;
6. 如果high <= low, 说明数组本身有序，返回0.
7. 如果high > low, 两个下标直接的元素个数就是子数组长度，即high - low + 1**


### 性能
执行用时 :68 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :16 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findUnsortedSubarray($nums) {
        $len = count($nums);
        if ($len <= 0) return 0; 
        
        $max = $nums[0];
        $min = $nums[$len - 1];

        $high = 0;
        $low = $len - 1;

        for ($i = 1; $i < $len; $i++) {
            if ($nums[$i] > $max) $max = $nums[$i];
            if ($nums[$len - 1 - $i] < $min) $min = $nums[$len - 1 - $i];

            if ($nums[$i] < $max) $high = $i;
            if ($nums[$len - 1 - $i] > $min) $low = $len - 1 - $i;
        }

        return $high > $low ? $high - $low + 1 : 0;
    }
}
```

### 参考
[@xyt](/u/xyt/) --- [评论](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/comments/76131)