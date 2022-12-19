### 解题思路
思路见代码注释

### 代码

```php
class Solution {

    /**
     * @param Integer[] $heights
     * @return Integer
     */
    function largestRectangleArea($heights) {
        // 利用辅助栈，O(n)
        $length = count($heights);
        $max = 0;
        $stack = new SplStack();
        $stack->push(-1);
        for ($i = 0; $i <= $length - 1; ++$i) {
            // 栈不为空且找到了当前柱子的右边界，需要处理栈。左边界是栈中下一个元素
            while ($stack->top() != -1 && $heights[$i] < $heights[$stack->top()]) {
                $current = $stack->pop();
                $area = $heights[$current] * ($i - $stack->top() - 1);
                $max = max($area, $max);
            }
            $stack->push($i);
        }

        // 一次遍历完，处理栈中剩余的，这些柱子都是未找到右边界的
        while ($stack->top() != -1) {
            $current = $stack->pop();
            $area = $heights[$current] * ($length - $stack->top() - 1);
            $max = max($area, $max);
        }

        return $max;
    }
}
```