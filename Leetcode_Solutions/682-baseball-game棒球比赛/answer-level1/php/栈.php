### 解题思路
使用栈即可

### 运行效率
执行用时 :4 ms, 在所有 php 提交中击败了100.00%的用户
内存消耗 :15.2 MB, 在所有 php 提交中击败了11.11%的用户

### 注意
代码16行，压栈顺序是top2, top1, cur

### 代码

```php
class Solution {

    /**
     * @param String[] $ops
     * @return Integer
     */
    function calPoints($ops) {
        $stack = [];

        foreach ($ops as $op) {
            switch ($op) {
                case '+':
                    $top1 = array_pop($stack);
                    $top2 = array_pop($stack);
                    $cur = $top1 + $top2;
                    array_push($stack, $top2, $top1, $cur);
                    break;
                case 'D':
                    $cur = end($stack) * 2;
                    array_push($stack, $cur);
                    break;
                case 'C':
                    array_pop($stack);
                    break;
                default :
                    array_push($stack, $op);
                    break;
            }
        }
    
        return array_sum($stack);
    }
}
```