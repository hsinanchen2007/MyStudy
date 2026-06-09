### 解题思路

执行用时击败 95% 的用户。

该题主要就是栈的运用。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        if(!$s) return true;
        $stack = new SplStack();
        $len = strlen($s);
        if(0 != $len % 2) return false; //奇数长度，直接返回false
        $left = ['(' => 1, '{' => 1, '[' => 1];
        for($i = 0; $i < $len; $i++) {
            //isset 字典查询 效率高
            if(isset($left[$s[$i]])) { 
                //所有左括号 直接入栈
                $stack->push($s[$i]);
            } else {
                if($stack->isEmpty()) return false;
                //判断栈顶和当前字符是否匹配，如果不匹配就返回false
                if($s[$i] == ')' && $stack->pop() != '(') return false;
                if($s[$i] == '}' && $stack->pop() != '{') return false;
                if($s[$i] == ']' && $stack->pop() != '[') return false;
            }
        }
        //最后 判断栈是否为空
        return $stack->isEmpty();
    }
}
```