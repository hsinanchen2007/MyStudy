### 解题思路
此处撰写解题思路
开始是思考计算重叠部分的面积，判断是否为正。
后来发现，考虑重叠的情况会很多，不好计算面积，所以转向考虑不重叠的情况，发现只有四种情况。
分别是：1在2 的两侧
        左：stratX1 >= endx2  右：endX1 <= startx2;
        上面：startY1 >= endY2 下面：endY1 <=startY2;
所有，判断是否满足，满足就是不重叠，不满足就是重叠。

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int startX1 = rec1[0];
        int startY1 = rec1[1];
        int endX1 = rec1[2],endY1 = rec1[3];

        int startX2 = rec2[0],startY2 = rec2[1];
        int endX2 = rec2[2],endY2 = rec2[3];
        if(startX1 >= endX2 || startX2 >= endX1 || startY1 >= endY2 || startY2 >= endY1)
            return false;
        return true;

    }
}
```