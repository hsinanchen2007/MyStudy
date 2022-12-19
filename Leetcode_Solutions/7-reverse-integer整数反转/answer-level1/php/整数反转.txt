两种思路：
1. 利用整数取模；
2. 利用字符串函数；
```
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
     //执行用时 :8 ms, 在所有 PHP 提交中击败了86.81%的用户
     //内存消耗 :14.5 MB, 在所有 PHP 提交中击败了90.98%的用户
    function reverse($x) {
        //判断是否整数
        if(!is_int($x)) return 0;
        $max = pow(2,31) - 1;
        $min = pow(-2,31);
        $res = 0;//倒叙的数字
        while($x>=10 || $x<=-10) {//只要不是个位数，就一直循环
            $mod = $x%10;//余数
            $x   = ($x-$mod)/10;
            $res = $res*10 + $mod;//倒叙的数字
        }
        //防止溢出
        if ($res > $max) return 0;
        if ($res < $min) return 0;
        return $res*10 + $x;
    }

    //执行用时 :16 ms, 在所有 PHP 提交中击败了30.14%的用户
    //内存消耗 :14.5 MB, 在所有 PHP 提交中击败了90.98%的用户
    //利用字符串函數來處理數字還是慢一些
    function reverse2($x) {
        $max = pow(2,31) - 1;
        $min = pow(-2,31);
        if(!is_int($x) || $x == 0 ) {
            return 0;
        }else{
            if($x > 0) {
                $res = (int)(strrev($x));//利用字符串函數
                return $res>$max?0:$res;//防止溢出
            }else {
                $x   = 0-$x;
                $res = -(int)(strrev($x));
                return $res<$min?0:$res;
            }
        }
    }
}
```
