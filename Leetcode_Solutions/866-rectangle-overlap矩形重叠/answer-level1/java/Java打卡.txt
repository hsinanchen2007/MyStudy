### 解题思路
Java打卡

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int x11 = rec1[0];
        int y11 = rec1[1];
        int x12 = rec1[2];
        int y12 = rec1[3];
        int x21 = rec2[0];
        int y21 = rec2[1];
        int x22 = rec2[2];
        int y22 = rec2[3];
        boolean xOverlap = !(x12 <= x21 || x22 <= x11);
        boolean yOverlap = !(y12 <= y21 || y22 <= y11);
        return xOverlap && yOverlap;

    }
}
```