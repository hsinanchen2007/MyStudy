```
    function reverse($x) {
        $f = $x < 0 ? '-' : '';
        $x = abs($x) . '';
        $len = strlen($x) - 1;
        $half = floor($len/2);
        for($i=0;$i<=$len;$i++){
            $target = $len - $i;
            $tmp = $x[$target];
            $x[$target] = $x[$i];
            $x[$i] = $tmp;
            if ($i == $half) {
                break; //至此已完成整个字符串字符的位置替换
            }
        }
        $x = intval($f . $x);
        if ($x > 2147483647 || $x < -2147483646) {
            return 0;
        } else {
            return $x;
        }
    }
```
思路：
1.先判断是否负数，获取符号；
2.转换$x为字符串，获取字符长度；
3.循环：根据字符索引替换相应字符位置，循环次数为字符长度的一半（舍弃法取整），即完成了整个字符串的替换；
4.判断是否溢出；
