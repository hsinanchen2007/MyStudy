### 解题思路
这是一个n*m的二维矩阵，并且有排序的规律。一行中，最左边的最小；一列中，最下面的最大。

我们可以找一个数，比如左下角的数，左下角的数满足性质：在当前行中最小，在当前列中最大。

那么，我们选取这个数后，如果目标数大于这个数，我们可以把当前列消掉；如果目标数小于这个数，我们可以把当前行消掉。

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @param Integer $target
     * @return Boolean
     */
    function findNumberIn2DArray($matrix, $target) {
        $row_count = count($matrix);
        $column_count = count($matrix[0]);

        $i = $row_count-1;
        $j = 0;
        $flag_element = $matrix[$i][$j];

        while($i>=0 && $j<$column_count){
            if($flag_element>$target) $i--;
            if($flag_element<$target) $j++;
            if($flag_element==$target) return true;
            $flag_element = $matrix[$i][$j];
        }
        return false;
    }
}
```