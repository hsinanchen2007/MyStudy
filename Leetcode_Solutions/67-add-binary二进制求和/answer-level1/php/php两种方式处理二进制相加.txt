### 解题思路
有两种方法：
第一种方法，直接二进制相加，以更长的二进制为基准循环，如果相加的值大于等于2说明有进一位，若值奇数本次为1，若为偶数本次为0，同时要判断后一位的元素是否存在，不存在这自动补进一位1；若相加的值小于2，则取本身的值即可。
### 代码

```php
<?php
    class Solution {
    /**给定两个2进制，求和
     * @param String $a
     * @param String $b
     * @return String
     */
        function addBinary($a, $b) {
            $a_arr=str_split($a); //字符串转数组
            $b_arr=str_split($b);
            $result = [];
            $enter_one = 0;
            if (strlen($a) >= strlen($b)) {
                $long_temp_arr = $a_arr;
                $short_temp_arr = $b_arr;
            } else {
                $long_temp_arr = $b_arr;
                $short_temp_arr = $a_arr;
            }
            $long_temp_arr = array_reverse($long_temp_arr);
            $short_temp_arr = array_reverse($short_temp_arr);

            for ($i=0;$i<count($long_temp_arr);$i++) {
                $temp_short_num = isset($short_temp_arr[$i]) ? $short_temp_arr[$i] : 0;
                $temp_sum = $long_temp_arr[$i] + $temp_short_num + $enter_one;
                if ($temp_sum > 1) {
                    $more_sum = $temp_sum % 2 == 1 ? 1 : 0;  //奇数取1，偶数取0（奇数最大3，偶数最大2）
                    array_unshift($result,$more_sum);
                    if (!isset($long_temp_arr[$i+1])) {
                        //判断长的数组后一位是否存在，不存在多取1
                        array_unshift($result,1);
                        break;
                    }
                    $enter_one = 1;//进一步的值，
                } else {
                    //直接拿值
                    $enter_one = 0;//进一步的值，
                    array_unshift($result, $temp_sum);
                }
            }
            $result = implode("",$result);
            return $result;
        }
    }
    $test = new Solution();
    $result = $test->addBinary(11,1);
    var_dump($result);
?>
```
第二种方法：将两个二进制转换成十进制，相加，再转换成二进制即可。
短板：由于二进制过长，加减乘除会出现科学计数问题，所以要使用任意两个精度的函数去进行加、乘、除、取余。
在该平台执行，不支持这些内置方法，本地操作可执行。
```php
<?php
    class Solution {
    /**给定两个2进制，求和
     * @param String $a
     * @param String $b
     * @return String
     */
        function addBinary($a, $b) {
            $a_arr = str_split($a);
            $b_arr = str_split($b);
            $sum_a = $j = 0;
            for($i = count($a_arr)-1; $i >= 0; $i--) {
                $sum_a = bcadd($sum_a,bcmul($a_arr[$i],bcpow(2,$j)));             
                $j++;
            }
            $sum_b = $j=0;
            for($i = count($b_arr)-1;$i >= 0;$i--){
                $sum_b = bcadd($sum_b,bcmul($b_arr[$i],bcpow(2,$j)));   
                $j++;
            }
            $result = [];
            $sum = bcadd($sum_a,$sum_b);
            if ($sum==0) {
                return $a;
            } else {
                do {
                    $dd = bcmod($sum,2);
                    array_unshift($result,$dd);
                    $sum = bcdiv($sum,2);
                } while ($sum > 0);
                $result = implode("",$result);
                $result = strval($result);
                return $result;
            }
        }
    }
    $test = new Solution();
    $result = $test->addBinary(11,1);
    var_dump($result);
?>
```