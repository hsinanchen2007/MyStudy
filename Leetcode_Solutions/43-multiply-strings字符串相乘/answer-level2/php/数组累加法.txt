### 解题思路
预先开辟数组空间，依次往对应的位置写入本次的对10取模结果，如果>10，高位进1，简单易懂，但是有应该有更优解法没想到

### 代码

```php
class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function multiply($num1, $num2) {
        if($num1 == '0' || $num2 == '0'){
            return '0';
        }
        $arr1 = str_split($num1);
        $arr2 = str_split($num2);
        $cnt1 = count($arr1);
        $cnt2 = count($arr2);

        $ret = [];
        for ($i=0; $i < $cnt1 + $cnt2 ; $i++) { 
            $ret[$i] = 0;
        }

        for ($j = $cnt2-1; $j >= 0; $j --) { 
        for ($i = $cnt1-1; $i >= 0 ; $i --) {
                $tmp = $arr1[$i] * $arr2[$j];
                $mod = $tmp % 10;
                $up = intval($tmp/10);
                $ret[$i+$j+1] += $mod;
                $ret[$i+$j] += $up;

                if($ret[$i+$j+1] >= 10){
                    $mod = $ret[$i+$j+1] % 10;
                    $up = intval($ret[$i+$j+1]/10);
                    $ret[$i+$j+1] = $mod;
                    $ret[$i+$j] += $up;
                }
            }
        }
        while ($ret[0] == 0) {
            array_shift($ret);
        }
        return implode('', $ret);
    }
}
```