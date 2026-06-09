解答：

本题主要考察溢出。int32 无符号数值范围  [−2147483648,2147483647] 。

```php
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $max = pow(2,31) -1;
        $min = -$max+1;
        $maxLast = $max % 10; //最大值个位数
        $minLast = $min % 10; //最小值个位数

        $rev = 0;
        while ($x != 0) {
            $pop = $x % 10;
            $x = intval($x / 10); //取整

            //最大值溢出
            if ($rev > $max / 10 || ($rev == $max / 10 && $pop > $maxLast) ) {
                return 0;
            }

            //最小值溢出
            if ($rev < $min / 10 || ($rev == $min / 10 && $pop < $minLast) ) {
                return 0;
            }

            
            $rev = $rev * 10 + $pop;
        }

        return $rev;
    }
}
```

- x是正数情况：如果当前的数值 rev * 10 > max，说明溢出了；如果 rev  ==  max /10 ，那么只要要加的数pop大于个位数7，那么也是溢出。
- x是负数情况：如果当前的数值 rev * 10 < min，说明溢出了；如果 rev == min / 10，那么只要要加的数(负数的取模还是负数)小于 -8，那么还是溢出。

- 注意：PHP里面两数相除是浮点数，有小数。