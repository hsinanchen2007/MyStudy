### 解题思路
1.反正法：如果 A + B == B + A 成立，则 A + B ！== B + A也成立
2.利用辗转相除法计算出最大公约数(字符串长度) 

### 代码

```php
class Solution {

    /**
     * @param String $str1
     * @param String $str2
     * @return String
     */
    function gcdOfStrings($str1, $str2) {
        if ($str1.$str2 !== $str2.$str1) {
            return "";
        }
        $str1_l = strlen($str1);
        $str2_l = strlen($str2);
        return substr($str1,0,gcd($str1_l, $str2_l));
    }
}
function gcd($a, $b){
    while($b != 0) {
        $temp = $b;
        $b = $a%$b;
        $a = $temp;
    }
    return $a;
}
```