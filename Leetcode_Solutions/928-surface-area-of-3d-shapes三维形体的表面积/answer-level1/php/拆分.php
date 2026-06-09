### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid) {
        // 正方形总数
        $total = 0;
        // 叠加盖住的面
        $cover = 0;
        // 给定数组
        $length = count($grid);

        for ($i = 0; $i < $length; $i++) {

            for ($j = 0; $j < $length; $j++) {

                $total += $grid[$i][$j];

                if ($grid[$i][$j] > 0) {
                    // 叠起来接触面
                    $cover += $grid[$i][$j] - 1;
                }
                if ($i > 0) {
                    // 行重叠
                    $cover += min($grid[$i - 1][$j], $grid[$i][$j]);
                }
                if ($j > 0) {
                    // 列重叠
                    $cover += min($grid[$i][$j - 1], $grid[$i][$j]);
                }
            }
        }

        return $total * 6 - $cover * 2;
}
}
```
拆分成 行和列 和叠加的面数 = 阴影部分面积
正方体个数乘6  = 全部面积 