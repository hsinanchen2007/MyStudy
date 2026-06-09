### 解题思路
统计字母出现次数 
相减


```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Integer
     */
    function minSteps($s, $t) {

        $sArr = str_split($s,1);
        $tArr = str_split($t,1);
        $num = 0;

        foreach(array_unique($sArr) as $key =>$value){
            $num1=0;
            $num2=0;
            foreach($sArr as $key1 => $value1){
                if($value == $value1){
                    $num1++;
                }
            }

            foreach($tArr as $key2 => $value2){
                if($value == $value2){
                    $num2++;
                }
            }

            if($num1 - $num2 > 0){
                $num =$num + $num1 - $num2;
            }
        }
        return $num;
    }
}




```