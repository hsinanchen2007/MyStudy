### 解题思路
从顶部看，由该形状生成的阴影将是网格中非零值的数目。
从侧面看，由该形状生成的阴影将是网格中每一行的最大值。
从前面看，由该形状生成的阴影将是网格中每一列的最大值。

以上3个数加和即可，两次遍历

### 性能
执行用时 :24 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :15.6 MB, 在所有 PHP 提交中击败了25.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function projectionArea($grid) {
        $area = 0;
        for ($i  = 0; $i < count($grid); $i++) {
            $row_high = $col_high = 0;
            for ($j = 0; $j < count($grid[$i]); $j++) {
                if ($grid[$i][$j] > 0) $area++;
                $row_high = max($row_high, $grid[$i][$j]);
                $col_high = max($col_high, $grid[$j][$i]);
            }

            $area += $row_high + $col_high;
        }

        return $area;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N ^ 2)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/projection-area-of-3d-shapes/solution/san-wei-xing-ti-tou-ying-mian-ji-by-leetcode/](https://leetcode-cn.com/problems/projection-area-of-3d-shapes/solution/san-wei-xing-ti-tou-ying-mian-ji-by-leetcode/)