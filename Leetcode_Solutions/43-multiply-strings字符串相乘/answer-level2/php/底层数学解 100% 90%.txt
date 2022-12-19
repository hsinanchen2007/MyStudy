### 解题思路
把乘法法则拆开使用

### 代码

```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function multiply($num1, $num2) {
        if ($num1 == '0' || $num2 == '0') {
            return '0';
        }

        $arr = [];
        $len1 = strlen($num1);
        $len2 = strlen($num2);
        $arr[0] = 0;
        for ($i=0; $i < $len1; $i++) {
            for ($j = 0; $j < $len2; $j++) {
                if(!isset($arr[$i+$j+1])) $arr[$i+$j+1] = 0;
                $arr[$i+$j+1] +=  (int) $num1[$i] * (int) $num2[$j];
                //shift one pos to the right 
                //for the reserved pos for the possible carry
            }
        }

        $is = 0;
        $count = count($arr);
        //from tens position going up
        for ($i=$count-1; $i>=0; $i--) {
            $arr[$i] += $is;//add the carry
            $is = floor($arr[$i]/10);//calculate the carry for the next digit
            $arr[$i] = $arr[$i]%10;//get the current digit
        }

        return ltrim(implode('', $arr), '0');//combine the digits and remove the leading 0 if any
    

    }
}
```