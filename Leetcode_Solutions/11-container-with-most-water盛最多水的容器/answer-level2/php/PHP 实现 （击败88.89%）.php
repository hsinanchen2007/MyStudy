### 解题思路
第一种是求出各种可能的子串，得到各个的面积，取最大值，然而超时了
第二种：从两端开始向中间收缩计算，矮的那一侧向中间靠，因为这样才能在横向缩小时把短板提高，两个相等时，比较各个的下一个的高低，更高的端收缩

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     耗时过长
     */
    function maxArea1($height) {
        $max = 0;
        $count = count ($height);
        $start = 0;
        while (true) {
            $value = $height[$start];
            for ($i = $start + 1;$i <= ($count -1);$i ++) {
                $h = $value > $height[$i] ? $height[$i] : $value;
                $vol = $h * ($i - $start);
                if ($vol > $max)
                    $max = $vol;
            }
            ++$start;
            if ($start >= ($count - 2)) break;
        }
        return $max;
    }
    function maxArea($height) {
        $max = 0;
        $count = count ($height);
        $start = 0;
        $end = $count -1;
        while (true) {
            $diff = $end - $start;
            if ($height[$start] > $height[$end]) {
                $h = $height[$end];
                --$end;
            } elseif ($height[$start] == $height[$end]) {
                $h = $height[$start];
                if ($height[$start + 1] > $height[$end - 1]) {
                    ++ $start;
                } else {
                    -- $end;
                }
            } else {
                $h = $height[$start];
                ++ $start;
            }
            $max = max($max, $h * $diff);
            if ($end <= $start) break;
        }
        return $max;
    }
}
```