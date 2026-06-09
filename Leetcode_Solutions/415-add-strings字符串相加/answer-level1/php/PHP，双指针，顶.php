利用双指针操作，非常nice~
```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function addStrings($num1, $num2) {
        $num1Len = strlen($num1);
        $num2Len = strlen($num2);

        // 以防止两个字符串长度不一致
        while ($num1Len < $num2Len) {
            $num1 = '0'.$num1;
            $num1Len ++;
        }
        while ($num1Len > $num2Len) {
            $num2 = '0'.$num2;
            $num2Len ++;
        }

        $i = $num1Len - 1;
        $j = $num2Len - 1;
        // 初始进位
        $carry = 0;
        $res = '';

        while ($i >= 0 || $j >= 0) {
            // + carry的意思是上一个进1，所以现在就要+1
            $tmp = $num1[$i] + $num2[$j] + $carry;
            $carry = floor($tmp / 10);
            $res = ($tmp % 10) . $res;
            $i --;
            $j --;
        }

        // 到最后carry里面还有1的话，就把1放到最前面
        if ($carry == 1) {
            $res = '1'.$res;
        }


        return $res;
    }
}
```