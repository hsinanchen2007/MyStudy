### 解题思路
借鉴的别人的

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
      //执行用时 :8 ms, 在所有 php 提交中击败了63.64%的用户
      //内存消耗 :15.1 MB, 在所有 php 提交中击败了100.00%的用户
      function toHex($num) {
        $hex = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'];
        $str = '';
        if($num == 0){
            return "0";
        }
        $temp = $num;
        if($num < 0){
            $temp = abs($num) - 1;
        }
        while($temp >= 16){
            $str .= $hex[$temp % 16];
            $temp = intval($temp/16);
        }
        $str .= $hex[$temp];
        $str = strrev($str);
        if($num < 0){
            $str = (string)$str;
            for($i=0;$i<strlen($str);$i++){
                $str[$i] = $hex[15 - array_search($str[$i],$hex)];
            }
            $str = str_pad($str,8,'f',STR_PAD_LEFT);
        }
        return $str;
    }

    function toHex2($num) {
        $hexString = "0123456789abcdef";
        $s = '';
        while($num != 0){
            $end = $num&15;
            $s = $hexString[$end] . $s;
            //无符号右移,右移赋值
            $num >>=4;
        }
        if(strlen($s) == 0){
            $s = "0";
        }
        return $s;
    }
}
```