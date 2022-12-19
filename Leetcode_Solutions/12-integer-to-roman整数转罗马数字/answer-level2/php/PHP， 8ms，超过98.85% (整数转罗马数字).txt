### 解题思路
基本没什么取巧的地方，就是先整理出来阿拉伯数字转罗马数字的方法，然后使用编程语言实现。

先算千位，用空字符串拼接M， 再算百位，根据不同情况拼接C,D,M。依次到个位即可。
### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    function intToRoman($num) {
        $str = "";
        $m = floor($num / 1000);
        $str .= str_repeat("M", $m);

        $tem = $num % 1000;
        $c = floor($tem / 100);
        if($c==9){
            $str .= "CM";
        }elseif($c <4){
            $str .= str_repeat("C", $c);
        }elseif($c == 4){
            $str .= "CD";
        }else{
            $str .= "D".str_repeat("C", $c-5);
        }

        $tem = $tem % 100;
        $x = floor($tem / 10);
        if($x==9){
            $str .= "XC";
        }elseif($x <4){
            $str .= str_repeat("X", $x);
        }elseif($x == 4){
            $str .= "XL";
        }else{
            $str .= "L".str_repeat("X", $x-5);
        }

        $i = $tem % 10;
        if($i==9){
            $str .= "IX";
        }elseif($i < 4){
            $str .= str_repeat("I", $i);
        }elseif($i == 4){
            $str .= "IV";
        }else{
            $str .= "V".str_repeat("I", $i-5);
        }
        return $str;
    }
}
```