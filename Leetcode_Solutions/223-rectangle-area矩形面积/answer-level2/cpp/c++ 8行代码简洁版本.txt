思路和其他题解是差不多的，通过判断两个矩形边的相对位置，判断是否存在相交（完全包含也属于相交的一种）。
```
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (C-A)*(D-B),area2=(G-E)*(H-F),cross=0;
        if(max(A,E)<min(C,G)&&max(B,F)<min(D,H)) cross=(min(C,G)-max(A,E))*(min(D,H)-max(B,F));
        return area1+area2-cross;
    }
};
```