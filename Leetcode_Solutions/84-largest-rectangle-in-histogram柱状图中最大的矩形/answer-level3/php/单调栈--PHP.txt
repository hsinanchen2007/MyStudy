### 解题思路
利用单调栈。遍历数组，把数组元素下标压栈，直到当前元素比栈顶元素大，挨个出栈，计算能覆盖当前出栈元素的最大面积。

**说明：单调栈是指栈中元素是有序的，数据出栈序列为单调递增序列则称单调递增栈，否则为单调递减栈。**

完整的说明示意图可以参考文末的参考内容, 需要画图理解。模拟压栈弹栈的过程。

重点在于理解栈中数据的情况，A入栈，B入栈，遇到C，B出栈。
[A, B, C]
A < B > C

### 性能
执行用时 :32 ms, 在所有 PHP 提交中击败了86.21%的用户
内存消耗 :18.5 MB, 在所有 PHP 提交中击败了45.00%的用户


### 代码

```php
class Solution {

    /**
     * @param Integer[] $heights
     * @return Integer
     */
    function largestRectangleArea($heights) {
        // 比栈顶元素小大才出栈，最后一个元素后需要补一个0，让最后一个元素有机会出栈。
        array_push($heights, 0);
        
        $stack = [];
        $area = 0;
        for ($i = 0; $i < count($heights); $i++) {
            while (!empty($stack) && $heights[end($stack)] > $heights[$i]) {
                $top = array_pop($stack);
                $width = empty($stack) ? $i : ($i - end($stack) - 1);
                $area = max($area, $heights[$top] * $width);
            }

            array_push($stack, $i);
        }

        return $area;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://blog.csdn.net/Zolewit/article/details/88863970](https://blog.csdn.net/Zolewit/article/details/88863970)
[https://leetcode-cn.com/problems/largest-rectangle-in-histogram/comments/175122](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/comments/175122)