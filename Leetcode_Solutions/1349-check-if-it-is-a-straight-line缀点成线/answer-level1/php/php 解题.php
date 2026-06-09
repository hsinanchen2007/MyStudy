使用斜率进行解题 $\frac{y_1-y_0}{x_1-x_0} = \frac{y_i-y_{i-1}}{x_i-x_{i-1}}$ 转换后成为 $(y_1-y_0) * (x_i-x_{i-1})=(x_1-x_0) * (y_i-y_{i-1})$  
```
class Solution {

    /**
     * @param Integer[][] $coordinates
     * @return Boolean
     */
    function checkStraightLine($coordinates) {
        $x = $coordinates[1][0] - $coordinates[0][0];
        $y = $coordinates[1][1] - $coordinates[0][1];
        $len = count($coordinates);
        $i = 2;
        while ($i < $len) {
            // 使用斜率进行判断
            if ( ($coordinates[$i][0] - $coordinates[$i -1][0]) * $y != ($coordinates[$i][1] - $coordinates[$i -1][1]) * $x) {
                return false;
            }
            
            if ($i + 1 < $len) {
            // 使用斜率进行判断
                if (($coordinates[$i +1][0] - $coordinates[$i][0]) * $y != ($coordinates[$i +1][1] - $coordinates[$i][1]) * $x) {
                    return false;
                }
            }
            
            $i += 2;
            if ($i >= $len) {
                $i --;
            }
        }
        return true;
    }
}
```
