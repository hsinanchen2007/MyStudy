### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return Integer
     */
    function myAtoi($str) {
        $str = ltrim($str);//消除开头的空格

        //如果为空直接返回0
        if($str=="") return 0;
        //如果首字母不是数字且不是+-，返回0
        elseif(!is_numeric($str[0]) && $str[0]!="-" && $str[0]!="+") return 0;

        //把字串打散为字符
        $chars = str_split($str);
        $final = "";
        for($i=0;$i<count($chars);$i++){
            if($i==0 && $chars[$i]=="-") $final = $chars[$i];
            elseif($i==0 && $chars[$i]=="+") continue;
            elseif(is_numeric($chars[$i])) $final .= $chars[$i];
            elseif($chars[$i]==" ") break;
            else{
                break;
            }
        }

        //检查大小
        $final = $final > 2**31-1? 2**31-1:$final;
        $final = $final < -2**31? -2**31:$final;

        return (int)$final;

    }
}
```