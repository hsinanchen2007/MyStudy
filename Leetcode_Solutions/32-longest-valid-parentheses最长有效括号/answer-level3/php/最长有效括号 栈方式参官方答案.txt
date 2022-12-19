### 解题思路
时间复杂度： O(n) 。 n是给定字符串的长度。

空间复杂度： O(n) 。栈的大小最大达到 n

### 代码

```php
class Solution {

    /**
     * 参考官网
     *
     *  0. 向队列push(-1) 用来处理第一个成对栈想隔个数
     *  1. 当遇见"("想栈 push $i;
     *  2. 遇见")"栈 pop
     *    2.1 当栈为空 push($i) 用以标记起始分割位置
     *    2.2 计算成对的个数$i-当前队列中的 top
     *  3. 其实就是计算步长，用分割点来标识成对数量
     * @param String $s
     * @return Integer
     */
    function longestValidParentheses($s) {
        $stack = new SplStack();
        $stack->push(-1);
        $length = strlen($s);
        $maxans = 0;

        for ($i = 0; $i < $length; $i++) {
            if ($s[$i] == "(") {
                $stack->push($i);
            } else {
                $stack->pop();
                // 标记分割点
                if ($stack->isEmpty()) {
                    $stack->push($i);
                } else {
                    // 计算最大的成对数量
                    $maxans = max($maxans, $i - $stack->top());
                }
            }
        }
        return $maxans;
    }
}

```