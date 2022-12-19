class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $str1 = (string)$x;
        $sign = 0;
        //如果是负数
        if (substr_count($str1,'-')) {
            $sign = 1;
            $str1 = substr($str1,1);
        }
        $str2 = strrev($str1);
        if ($sign) {
            $str2 = '-' . $str2;
        }
        $num = (int)$str2;
        if ($num > 2147483647 || $num < -2147483648) {
            return 0;
        }
        return $num;
    }
}