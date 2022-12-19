感谢高赞题解，真心看不懂题目

```php
class Solution
{

    /**
     * @param String $seq
     * @return Integer[]
     */
    function maxDepthAfterSplit($seq)
    {
        // 思路：栈 创建一个栈，遍历 seq，遇到 '(' 入栈，遇到 ')' 弹出。在这样的规则下，'(' 入栈时栈的深度就对应着当前括号对的嵌套深度深度。
        // 将奇数深度的括号分成一组，将偶数深度的括号分成一组，分别用 0 和 1 标记即可。
        $n = strlen($seq);
        $ans = array_fill(0, $n, 0);
        $depth = 0;
        for ($i = 0; $i < $n; ++$i) {
            $char = substr($seq, $i, 1);
            if ($char == '(') {
                // 入栈，栈深度增加
                $ans[$i] = $depth % 2;
                $depth++;
            } else {
                // 出栈，栈深度减少
                $depth--;
                $ans[$i] = $depth % 2;
            }
        }
        return $ans;
    }
}
```
