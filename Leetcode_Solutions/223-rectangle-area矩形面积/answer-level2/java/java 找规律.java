**思路**
两个可能重叠的矩形总面积就是两个矩形的面积之和减去重叠部分的面积即可。
$ansArea = area1 + area1 - commonArea$
其中，两个矩形可能没有重叠，因此$commonArea$可能为0。代码很简单，如下：

```java
    public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        if (E >= C || G <= A || H <= B || F >= D) {
            // 不相交
            return area1 + area2;
        }

        int leftBottomX = Math.max(A, E);
        int leftBottomY = Math.max(B, F);
        int rightUpX = Math.min(C, G);
        int rightUpY = Math.min(D, H);
        int commonArea = (rightUpX - leftBottomX) * (rightUpY - leftBottomY);
        return area1 + area2 - commonArea;
    }
```