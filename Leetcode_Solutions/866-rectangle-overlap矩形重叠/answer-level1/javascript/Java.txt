### 解题思路
找一张纸，画个坐标轴，两个矩形；只有在第二个矩形的（x4，y4）坐标在第一个矩形的（x1，y1）的上方，并且第二个矩形的（x3，y3）坐标在第一个矩形的（x2，y2）的下方时，才会出现重叠的情况。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec2[2]>rec1[0] && rec2[3]>rec1[1] && rec2[0]<rec1[2] && rec2[1]<rec1[3]){
            return true;
        }
        return false;
    }
}
```