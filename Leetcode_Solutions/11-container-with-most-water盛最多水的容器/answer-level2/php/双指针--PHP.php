### 解题思路
两次遍历很容易想到。性能比较低，这里使用双指针，一次遍历。

注：计算的是两竖线直接的面试，双指针注意每次移动的是短边。每次移动x轴都是固定长度。

### 性能
执行用时 :36 ms, 在所有 PHP 提交中击败了88.57%的用户
内存消耗 :16.9 MB, 在所有 PHP 提交中击败了5.79%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $front = 0;
        $rear = count($height) - 1;
        $area = 0;
        while ($front < $rear) {
            $area = max($area, ($rear - $front) * min($height[$front], $height[$rear]));
            if ($height[$front] < $height[$rear]) $front++;
            else $rear--;
        }

        return $area;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/](https://leetcode-cn.com/problems/container-with-most-water/solution/sheng-zui-duo-shui-de-rong-qi-by-leetcode/)