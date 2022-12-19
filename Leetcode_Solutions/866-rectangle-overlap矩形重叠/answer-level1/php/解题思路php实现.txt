# 思路
总结下来就两句话
1. 左边x轴的最大值 > 右边x轴的最小值
2. 上边y轴的最小值 < 下边y轴的最大值

```
class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2) {
        return (($rec1[2] > $rec2[0]) &&
            ($rec2[2] > $rec1[0]) &&
            ($rec1[3] > $rec2[1]) &&
            ($rec2[3] > $rec1[1]));
    }

```
