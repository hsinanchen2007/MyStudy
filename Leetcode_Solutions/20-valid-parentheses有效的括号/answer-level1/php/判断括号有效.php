### 解题思路
思路其实很简单，
只要是左括号就存到数组，
如果遇到右括号就判断数组中最后一位是不是对应的左括号，

看题解还有个判断字符长度奇偶提前结束的，想的就还要多一点

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $arr = [];
        $hash = [ // 对应数组
            '{'=>'}',
            '['=>']',
            '('=>')'
        ];
        $left = ['{','[','('];//判断数组
        $right = ['}',']',')'];
        for($i=0;$i<strlen($s);$i++){//开始循环
            if(in_array($s[$i],$left)){//如果是左括号 就存入数组
                $arr[] = $s[$i];
            }
            if(in_array($s[$i],$right)){//如果是右括号 判断
                if($hash[array_pop($arr)] != $s[$i]){//弹出数组最后一位 如果不是对应左括号则返回false
                    return false;
                }
            }
        }
        if($arr == []){ //最后是否还有剩余
            return true;
        }else{
            return false;
        }
    }
}
```