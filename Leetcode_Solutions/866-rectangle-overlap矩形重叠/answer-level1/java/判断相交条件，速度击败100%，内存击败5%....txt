需要注意如果矩形太大，可能会溢出
两个矩形最左下角的点与最右上角的点组成的矩形，长宽不会超过这两个矩形长宽的和

```java
public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
    int w1 = rec1[2] - rec1[0];
    int w2 = rec2[2] - rec2[0];
    int h1 = rec1[3] - rec1[1];
    int h2 = rec2[3] - rec2[1];
    int w = Math.max(rec1[2], rec2[2]) - Math.min(rec1[0], rec2[0]);
    int h = Math.max(rec1[3], rec2[3]) - Math.min(rec1[1], rec2[1]);
    return (w - w1) < w2 && (h - h1) <= h2;
}
```
