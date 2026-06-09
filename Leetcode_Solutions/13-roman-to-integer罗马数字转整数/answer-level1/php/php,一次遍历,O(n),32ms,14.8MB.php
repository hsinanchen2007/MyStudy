思路:

情况1 . 在位权不为4或9的情况下, 高位权对应的十进制数始终大于低位权, 举例: 10进制数532, 对应罗马数字DXXXII, 其中D对应十进制数500, X对应十进制数10, I对应十进制数1, 所以D>X>M

情况2 . 特殊情况只能位权为4和9的情况,举例: 10进制数49对应罗马数字XLIV, X对应10, L对应50, I对应1, V对应5, X<L, I<V

所以 , 依次遍历罗马数字并加入结果值,遇到情况2, 就减去上一次加进去的值即可


代码:

```
class Solution {
    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {

        $map = [
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
        ];

        $s_arr = str_split($s);
        $count = count($s_arr);
        $index = 0;
        $final = 0;

        while ($index < $count) {
            $pre = $index == 0 ? $map[$s_arr[$index]] : $map[$s_arr[$index - 1]];
            $cur = $map[$s_arr[$index]];

            if($cur > $pre){
                $final += $cur - $pre * 2;
            }else{
                $final += $cur;
            }
            $index ++;
        }

        return $final;
    }
}
```
