尝试将矩形分割。
当两个矩形不重叠的时候，直接计算面积返回即可。
当存在重合的时候，将两个矩形分成三部分，按照横坐标来划分，从左到右依次为不重叠区域，部分重叠区域，不重叠区域。
这里需要一些判断，为了简化代码，将矩形三部分扩展，对每个矩形都分成上述三个部分，不重叠区域，部分重叠区域，不重叠区域。
两个矩形的情况下，部分重叠区域是一样的，只需要计算一次，而且不重叠区域肯定有两个是为0的，不影响结果。
由于按照横坐标划分，可能存在不重叠而误判定为部分重叠区域的情况，因此还许多一个判断。
这样写下来，判断还挺多的。

这是代码
```
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int Ax = max(A,E), Bx = min(B,F), Cx = min(C,G), Dx = max(D,H);
        if(Ax>=Cx || F>=D || B>=H)return (C-A)*(D-B) + (G-E)*(H-F);
        return (Ax-A+C-Cx)*(D-B) + (Cx-Ax)*(Dx-Bx) + (Ax-E+G-Cx)*(H-F);
    }

        // int Ax = max(A,E), Bx = max(B,F), Cx = min(C,G), Dx = min(D,H);
        // if(Ax>=Cx)return (C-A)*(D-B) + (G-E)*(H-F);
        // return (C-A)*(D-B) - (Cx-Ax)*(Dx-Bx) + (G-E)*(H-F);
};
```

