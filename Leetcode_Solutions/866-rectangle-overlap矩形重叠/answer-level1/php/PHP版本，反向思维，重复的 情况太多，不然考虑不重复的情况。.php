### 解题思路
1.反向思维，找到不重复情况的条件。

2.动手画下图会一目了然。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2) {
        //不重合4种情况
        //rec1在rec2左边
        $left = $rec1[2] <= $rec2[0];
        //rec1在rec2右边
        $right = $rec2[2] <= $rec1[0];
        //rec1在rec2上边
        $top = $rec1[1] >= $rec2[3];
        //rec1在rec2下边
        $bottom = $rec2[1] >= $rec1[3];

        if ($left || $right || $top || $bottom) {
            return false;
        } else {
            return true;
        }

    }
}
```