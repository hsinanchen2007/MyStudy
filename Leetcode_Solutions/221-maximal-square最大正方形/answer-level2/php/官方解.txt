### 解题思路
动态规划，当前点最大矩形取决于周围三个点（**西，西北，北**）的最小边长，再加上***当前点的一个边长***，凑成最大正方形的边长。

### 代码

```php
class Solution {

    /**
     * @param String[][] $matrix
     * @return Integer
     */
    function maximalSquare($matrix) {
        $max = 0;

        //y轴
        for ($i = 0; $i < count($matrix); $i++) {
            //x轴
            for ($j = 0; $j < count($matrix[0]); $j++) {
                if ($matrix[$i][$j] == 0) {
                    $dp[$i][$j] = 0;
                } else {
                    $dp[$i][$j] = min($dp[$i-1][$j], $dp[$i-1][$j-1], $dp[$i][$j-1]) + 1; 
                }

                $max = max($dp[$i][$j], $max);
            }
           
        }
        return $max * $max;
    }
}
```