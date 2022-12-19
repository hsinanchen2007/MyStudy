class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2)
    {
        return !($rec1[2] <= $rec2[0]  //左
            || $rec1[0] >= $rec2[2]  //右
            || $rec1[1] >= $rec2[3]  //上
            || $rec1[3] <= $rec2[1]); //下
    }
}