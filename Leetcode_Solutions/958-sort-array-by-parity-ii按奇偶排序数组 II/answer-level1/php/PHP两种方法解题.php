# 方法一: 暴力破解 
- 两两交换,时间复杂度O(n²)
- 这种方法会超时,通不过的
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParityII($A) {
        $count = count($A);
        for ($i=0;$i<$count;$i++) {
            for ($j=$count - 1;$j>$i;$j--) {
                if ($i % 2 == 0 && $A[$i] % 2 != 0 && $A[$j] % 2 == 0) {
                    $tmp = $A[$i];
                    $A[$i] = $A[$j];
                    $A[$j] = $tmp;
                } elseif ($i % 2 != 0 && $A[$i] % 2 == 0 && $A[$j] % 2 != 0) {
                    $tmp = $A[$i];
                    $A[$i] = $A[$j];
                    $A[$j] = $tmp;
                }
            }
        }
        return $A;
    }
}
```

# 方法二: 遍历一次数组
- 时间复杂度O(n)
- 易理解
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParityII($A) {
        $count = count($A);
        $out = [];
        for ($i=0, $times=0, $times2=1;$i<$count;$i++) {
            if ($A[$i] % 2 == 0) {
                $out[$times] = $A[$i];
                $times+=2;
            }
            if ($A[$i] % 2 != 0) {
                $out[$times2] = $A[$i];
                $times2+=2;
            }
        }
        ksort($out);
        return $out;
    }
}
```
