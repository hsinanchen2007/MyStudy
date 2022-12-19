### 解题思路
辅助栈，但要注意特殊条件

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $stack = new SplStack();
        for($i=0;$i<strlen($s);$i++){
            if(in_array($s[$i],["(","[","{"])){
                $stack->push($s[$i]);
            }else{
                if($stack->isEmpty()) return false;
                if($s[$i]==")" && $stack->pop()!="(") return false;
                if($s[$i]=="]" && $stack->pop()!="[") return false;
                if($s[$i]=="}" && $stack->pop()!="{") return false;
            }
        }
        return $stack->isEmpty();
    }
}
```