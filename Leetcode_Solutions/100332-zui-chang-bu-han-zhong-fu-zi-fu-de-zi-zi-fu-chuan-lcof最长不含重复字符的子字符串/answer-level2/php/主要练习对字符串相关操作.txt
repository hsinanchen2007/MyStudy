### 解题思路
一次转换成数组，遍历过程中注意使用过程间的各种信息减少运算步骤。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $s_arr = strlen($s)?str_split($s):[];//构造数组
        $s_res = '';//中间过程比较字符串
        $s_res_length = 0;//字符串长度
        foreach($s_arr as $k => $v){
            $v_str = strpos($s_res,$v);//$v首次出现的位置
            if($v_str !== false){ //重复出现
                $s_res_length = max(strlen($s_res), $s_res_length);//暂存最长长度
                $s_res = substr($s_res,$v_str+1);//截取未重复部分
            }
            $s_res .= $v;//累加字符
        }
        return max(strlen($s_res), $s_res_length);//最后一次比较并返回
    }
}
```