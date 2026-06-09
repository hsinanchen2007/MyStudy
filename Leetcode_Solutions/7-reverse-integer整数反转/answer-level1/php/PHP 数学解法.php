```
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        # 负数判断
        $is_neg = false;
        if ($x<0) {
            $x = 0 - $x;
            $is_neg = true;
        }

        $count = strlen($x);
        # 拿到反转后数字
        $out = 0;
        for ($i=0,$j=$count-1;$i<$count;$i++,$j--) {
            $out = $out + $x%10 * pow(10,$j);
            $x = ($x - $x%10) / 10;
        }

        # 还原正或负
        $out = $is_neg ? 0 - $out : $out;

        # 判断是否已出
        $out = $out > pow(2,31) - 1 || $out < -pow(2,31) ? 0 : $out;

        return $out;
    }
}
```
