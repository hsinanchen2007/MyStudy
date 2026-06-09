### 解题思路
四个数组分成两两循环
ab的结果为a*b
计算ab结果各个值出现的次数
循环cd
在循环中计算出cd组合出的值并用0减去得到的就是ab求值后的key
判断key是否存在，如果存在则加上，否则继续


### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer[] $B
     * @param Integer[] $C
     * @param Integer[] $D
     * @return Integer
     */
    function fourSumCount($A, $B, $C, $D) {
        //$l = count($A);
        $value1 = [];
        foreach($A as $v) {
            foreach($B as $val) {
                $value1[] = $v + $val;
            }
        }
        $value1 = array_count_values($value1);
        //$value2 = [];
        $num = 0;
        foreach($C as $v) {
            foreach($D as $val) {
                //$value2[] = $v+$val;
                $key = 0-$v-$val;
                if (array_key_exists($key, $value1)) {
                    $num += $value1[$key];
                }
            }
        }
        //$value2 = array_count_values($value2);
        //$num = 0;
        //foreach($value1 as $k => $v) {
            /*foreach($value2 as $key => $val) {
                if($k+$key == 0) {
                    $num += $v * $val;
                }
            }*/
           // if (array_key_exists(-$k, $value2)) {
           //     $num += $v * $value2[-$k];
           // }
        //}
        return $num;
    }
}
```