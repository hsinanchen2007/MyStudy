**方法一：比较位置**
```
class Solution {
    /**
    * 思路：
    * 由题拖动两个矩形，只要有重叠部分，
    * 则一个矩形的左下角一定在另一个矩形右上角的左下，
    * 同时另一个矩形的左下角也一定在这个矩形右上角的左下。
    */
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec2[0] < rec1[2] && rec2[1] < rec1[3]
                 && rec2[2] > rec1[0] && rec2[3] > rec1[1];
    }
}
```

**方法二：投影到坐标轴**
```
class Solution {
    /**
    * 思路：
    * 由题可知，只要两个矩形有重叠部分，
    * 则两个矩形在X轴上的投影一定有重叠，同时两个矩形在Y轴上的投影也一定有重叠。
    */
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return (Math.min(rec1[2], rec2[2]) > Math.max(rec1[0], rec2[0]) &&
                Math.min(rec1[3], rec2[3]) > Math.max(rec1[1], rec2[1]));
    }
}
```
