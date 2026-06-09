### 解题思路
二分法，找到不在增长的元素

注意：遍历结束条件是front < rear 不能相等

### 性能
执行用时 :24 ms, 在所有 php 提交中击败了88.89%的用户
内存消耗 :16.3 MB, 在所有 php 提交中击败了25.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function peakIndexInMountainArray($A) {
        $front = 0;
        $rear = count($A) - 1;
        while ($front < $rear) {
            $mid = intval(($front + $rear) / 2);
            if ($A[$mid] < $A[$mid + 1]) {
                $front = $mid + 1;
            } else {
                $rear = $mid;
            }
        }

        return $front;
    }
}
```

参考：
[https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/solution/shan-mai-shu-zu-de-feng-ding-suo-yin-by-leetcode/](https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/solution/shan-mai-shu-zu-de-feng-ding-suo-yin-by-leetcode/)