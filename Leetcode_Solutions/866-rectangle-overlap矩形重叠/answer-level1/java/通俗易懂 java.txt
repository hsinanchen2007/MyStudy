### 解题思路
思路很简单，沿x轴和y轴分别考虑，如果两个矩形有公共区域，则在两条轴上都有公共区域

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return hasPublicRange(rec1[0], rec1[2], rec2[0], rec2[2]) && hasPublicRange(rec1[1], rec1[3], rec2[1], rec2[3]);
    }

    private boolean hasPublicRange(int a, int b, int c, int d) {
        assert a <= b;
        assert c <= d;
        return a < d && c < b;
    }
}
```