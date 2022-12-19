做目标检测的同学肯定很熟悉了，就是求IOU。
加入两个矩形面积是A1, A2，重合面积是A0。
用c++可能会因为A1+A2太大溢出，所以求和的时候可以调换一下顺序：A1-A0+A2


```c++ []
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(C-A) * abs(D-B);
        int area2 = abs(G-E) * abs(H-F);
        int x1 = max(A, E), x2 = min(C, G);
        int y1 = max(B, F), y2 = min(D, H);
        if(x2 <= x1 || y2 <= y1)
            return area1 + area2;
        else
            return area1 - (x2-x1)*(y2-y1) + area2;
    }
};
```

