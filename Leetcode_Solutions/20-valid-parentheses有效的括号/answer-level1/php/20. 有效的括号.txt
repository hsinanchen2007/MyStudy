### 解题思路
遍历输入字符串，利用堆栈思路（先入后出），保障括号的放入与拿取的顺序有序性，否则则判定字符串中存在无效的括号。

**几点注意事项：**
1. 第一个字符如果为闭合括号，则直接判为false；
2. 遍历输入字符串，如果字符为左括号（开始括号），则入栈，否则出栈末尾元素并判断是否与当前元素形成一组闭合括号，若非形成闭合括号返回false；
3. 重复步骤2，最终如果堆栈为空返回true，否则返回false。


### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $ruleArr = [
            '(' => ')',
            '{' => '}',
            '[' => ']',
        ];

        $stack = [];
        for($i=0; $i<strlen($s); $i++){
            if($i == 0 && in_array($s[$i], array_values($ruleArr))){
                return false;
            }

            if(in_array($s[$i], array_keys($ruleArr))){
                array_push($stack, $s[$i]);
            } else {
                $lastElement = array_pop($stack);
                if($ruleArr[$lastElement] != $s[$i]){
                    return false;
                }
            }
        }
        
        return empty($stack) ? true : false;
    }
}
```