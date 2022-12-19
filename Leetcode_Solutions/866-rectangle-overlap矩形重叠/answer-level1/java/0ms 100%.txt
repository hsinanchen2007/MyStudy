### 解题思路
纯枚举，逻辑

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int x1Left = rec1[0];
        int x1Right = rec1[2];
        int y1Left = rec1[1];
        int y1Right = rec1[3];
        int x2Left = rec2[0];
        int x2Right = rec2[2];
        int y2Left = rec2[1];
        int y2Right = rec2[3];

        if (x1Left <= x2Left && x1Right >= x2Right ||
                x1Left <= x2Left && x1Right > x2Left ||
            x2Left <= x1Left && x2Right >= x1Right ||
            x2Left <= x1Left && x2Right > x1Left){
            return y1Left <= y2Left && y1Right >= y2Right ||
                    y1Left <= y2Left && y1Right > y2Left ||
                    y2Left <= y1Left && y2Right >= y1Right ||
                    y2Left <= y1Left && y2Right > y1Left;
        }
        return false;
    }
}
```