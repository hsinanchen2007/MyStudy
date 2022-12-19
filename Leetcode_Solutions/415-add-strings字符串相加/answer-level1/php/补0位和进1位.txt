### 解题思路
本来想通过两个循环转成数字相加再转字符串，然后出现了科学计数，就感觉很麻烦，经过软神提醒就直接用字符串相加
然后，不断试错，修改。注意进位。
1.不同相同位数，前面补0
2.最后进位前面补1
![image.png](https://pic.leetcode-cn.com/1891b6705bfb1836de80a663b1d88639879ce6c89c28fa1172b52e61564cb452-image.png)


### 代码

```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function addStrings($num1, $num2) {
        $c1 = strlen($num1);
        $c2 = strlen($num2);
        $c = $c1 > $c2 ? $c1:$c2;
        $j = 0;
        if ($c1 - $c2 > 0) {
            for ($i=0; $i < ($c1 - $c2); $i++) { 
                $num2 = '0'.$num2;
            }
        }
        if ($c1 - $c2 < 0) {
            for ($i=0; $i < ($c2 - $c1); $i++) { 
                $num1 = '0'.$num1;
            }
        }
        $new = '';
        for ($i= $c-1; $i >=0; $i--) { 
            $n1 = $n2 = '';
            if (isset($num1[$i])) {
                $n1 = $num1[$i];
            }
            if (isset($num2[$i])) {
                $n2 = $num2[$i];
            }
            //两个都存在
            if (is_numeric($n1) && is_numeric($n2)) {
                $tmpN = $n1+$n2;
                if ($j == 1) {
                    $tmpN ++ ;
                    $j = 0;
                }
                if ($tmpN >= 10) {
                    $n = $tmpN % 10 ;
                    $new = $n.$new;
                    $j = 1;
                }else{
                    $new = $tmpN.$new;
                }
            }elseif (is_numeric($n1) && !is_numeric($n2)) {
                //只存在一个n1
                $new = $n1.$new;
            }elseif (is_numeric($n2) && !is_numeric($n1)) {
                $new = $n2.$new;
            }
        }
        if ($j == 1) {
            $new = '1'.$new;
        }
        return $new;
    }
}
```