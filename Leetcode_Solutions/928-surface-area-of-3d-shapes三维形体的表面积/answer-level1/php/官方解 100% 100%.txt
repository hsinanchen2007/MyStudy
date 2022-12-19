### 解题思路
感谢[@sweetiee](/u/sweetiee/)的讲解，稍作了一些改动

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid) {
        $surface_area = 0;
    
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[$i]); $j++) {
                $amount = $grid[$i][$j];//当前格中正方体的数量
    
                if ($amount > 0) {
                    //忽略水平方向贴面，计算摞在一起垂直立方体的表面积，前后左右各4面，加上下两面
                    $surface_area += $amount * 4 + 2;

                    //减去与左边和前边格子中立方体的贴面，需要减去的是更低那个立方体的垂直面积
                    if ($i > 0) $surface_area -= min($grid[$i - 1][$j], $amount) * 2;//与左边一格的贴面
                    if ($j > 0) $surface_area -= min($grid[$i][$j - 1], $amount) * 2;//与前边一格的贴面
                }
            }
        }
        return $surface_area;
    }
}
```