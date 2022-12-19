- 左边字符比右边字符小则减去当前值,否则加上当前值
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $arr = [
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
        ];
        $count = strlen($s);
        $num = 0;
        for ($i=0;$i<$count;$i++) {
            $next = $i+1;
            $num = $arr[$s[$next]] > $arr[$s[$i]] ? $num - $arr[$s[$i]] : $num + $arr[$s[$i]];
        }
        return $num;
    }
}
```
