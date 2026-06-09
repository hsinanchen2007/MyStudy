### 解题思路
利用 栈 的数据结构解决该问题,时间复杂度为：O(n)
将字符串各个元素，依次遍历，对比栈顶元素，如果该子字符串相对应的结束字符串 与栈顶元素相等
则弹出栈顶元素，否则 将子字符串压入栈内
最后 如果栈为空，则说明符合规则


### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        //利用 栈 的数据结构解决该问题
        if(!$s){
            return ture;
        }
        $length = strlen($s);
        $stack = array();
        $relation = array(
            '('=>')',
            ')'=>'(',
            '['=>']',
            ']'=>'[',
            '{'=>'}',
            '}'=>'{',
        );
        //将字符串各个元素，依次遍历，对比栈顶元素，如果该子字符串相对应的结束字符串 与栈顶元素相等
        // 则弹出栈顶元素，否则 将子字符串压入栈内
        //最后 如果栈为空，则说明符合规则
        for($i=0; $i<$length; $i++){
            $word = substr($s,$i,1);
            if($stack && $stack[count($stack)-1] == $relation[$word]){
                array_pop($stack);
            }else{
                $stack[] = $word;
            }
        }
        
        if(!empty($stack)){
            return false;
        }else{
            return true;
        }
    }
}


```