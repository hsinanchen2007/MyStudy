### 解题思路
1.给出字符串的长度不是偶数则直接返回 false
2.由于需要以正确的顺序关闭，考虑使用栈。遍历整个字符串，将开始标签`([{`等进行入栈操作，如果是结束标签`)]}`，则判断当前字符与栈顶字符是否匹配，匹配则弹出栈顶字符
3.最后判断整个栈是否为空

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $length = strlen($s);
        if($length == 0 || $length % 2 != 0){
            return false;
        }

        $stack = [];
        for($i=0;$i<$length;$i++){
            $char = $s[$i];
            if(in_array($char,['(','[','{'])){
                array_push($stack,$char);
            }else{
                if($char === ')' && end($stack) === '('){
                    array_pop($stack);
                }

                if($char === ']' && end($stack) === '['){
                    array_pop($stack);
                }

                if($char === '}' && end($stack) === '{'){
                    array_pop($stack);
                }
            }
        }
        return empty($stack);
    }
}
```