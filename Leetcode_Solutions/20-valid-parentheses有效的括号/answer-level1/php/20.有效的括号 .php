### 解题思路
1.初始化栈S
2.出现开括号入栈
3.出现闭括号判断栈S是否有匹配的开括号。  有:出栈，无:false
4.最后判断栈S是否为空。 是:true，否：false

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        #初始化栈S
        $S = array();
        $tmp = [
            '(' => ')',
            '{' => '}',
            '[' => ']'
        ];
        for($i=0;$i<strlen($s);$i++){
            if(isset($tmp[$s[$i]])){
                #入栈
                $S[] = $s[$i];
            }else{
                if($s[$i] == $tmp[$S[count($S)-1]]){
                    #出栈
                    array_pop($S);
                }else{
                    return false;
                }
            }
        }
        if(empty($S)){
            return true;
        }else{
            return false;
        }
    }
}
```