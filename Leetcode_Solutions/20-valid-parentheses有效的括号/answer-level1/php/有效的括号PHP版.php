主要考查栈的知识：遍历整个字符串，遇到左括号就入栈，然后遇到和栈顶对应的右括号就出栈，遍历结束后，如果栈为空，就表示全部匹配。


```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $map = [
            ")" => "(",
            "}" => "{",
            "]" => "[",
        ];

        $len = strlen($s);
        $stack = [];

        //s中出现map的key则弹出，没有出现则入栈
        for ($i =0; $i<$len; $i++) {
            if (isset($map[$s[$i]])){
                //s中出现map的key：如果能找到对应的map的值 (,{,[ 则说明有配对，则弹出
                if (isset($stack)  && $stack[0] == $map[$s[$i]]) {
                    array_shift($stack);
                } else { //仅找到后面的一部分，说明是不匹配的
                    return false;
                }
            } else {
                array_unshift($stack, $s[$i]);
            }
        }

        if (count($stack) > 0) {
            return false;
        }

        return true;
    }
}
```

使用`SplStack`代替数组模拟会更高效：
``` php
class Solution
{

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s)
    {
        $map = [
        ")" => "(",
        "}" => "{",
        "]" => "[",
        ];

        $len = strlen($s);


        // 奇数个字符，必然不符合
        if ($len % 2 == 1) {
            return false;
        }

        $stack = new SplStack();


        for ($i =0; $i<$len; $i++) {
            if (isset($map[$s[$i]])) {
                if (!$stack->isEmpty()  && $stack->top() == $map[$s[$i]]) {
                    $stack->pop();
                } else {
                    return false;
                }
            } else {
                $stack->push($s[$i]);
            }
        }

        if (count($stack) > 0) {
            return false;
        }

        return true;
    }
}
```

> 执行用时 :4 ms, 在所有 PHP 提交中击败了93.50的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了88.00%的用户

举例1：

对于输入: `()`，取出`(`去map里找，是不存在的，故入栈；然后取出`)`去map里找，有映射关系，值是`(`，与栈顶元素比较是相等的，则弹出。此时循环结束，栈为空，说明是符合的。

举例2：

对于输入: `)()(`，取出`)`去map里找，有映射关系，值是`(`，此时栈是空的，说明没有与之匹配的，不符合要求，后面都不用再比较了。

