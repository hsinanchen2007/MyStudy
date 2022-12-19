### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec1[0] < rec2[2] && rec1[2] > rec2[0] && rec1[1] < rec2[3] && rec1[3] > rec2[1];
    }
}
```第一个矩形[x1,y1,x2,y2] 第二个矩形[x3,y3,x4,y4] 那么当矩形要重叠时必须满足以下条件：
    x1<x4 && x2>x3 && y1<y4 && y2>y3
如果觉得不够形象，自己画图，把坐标标记出来，一目了然