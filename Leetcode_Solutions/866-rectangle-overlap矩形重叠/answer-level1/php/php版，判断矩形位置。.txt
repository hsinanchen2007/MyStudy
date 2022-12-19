纸上画下。就有思路了找找四个点的位置。  

```
class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2) {
        // 左下角。 右上角。
    	// rec2 在 rec1 上（2 的左下角 大于 1 的右上角）  下 （2的右上角 小于 1的左下角）  左 （）  右
    	return !(($rec2[1] >= $rec1[3]) || ($rec2[3] <= $rec1[1]) || ($rec2[2] <= $rec1[0]) || ($rec2[0] >= $rec1[2]));

    }
}
```