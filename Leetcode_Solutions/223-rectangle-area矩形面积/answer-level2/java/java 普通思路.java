这道题其实就是一个计算机视觉常用的IOU求解中的分母，主要是注意防止溢出。
这里的x，y分别代表x，y坐标轴上重叠的长度，通过将两个矩形求和再减去一个重叠的面积就是总面积。
```java
class Solution {
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long x = (long)Math.min(C, G) - (long)Math.max(A, E);
        long y = (long)Math.min(D, H) - (long)Math.max(B, F);
        long cross = 0;
        if (x > 0 && y > 0) {
            cross = x * y;
        }
        return (int) ((C - A) * (D - B) - cross + (G - E) * (H - F));
    }
}
```