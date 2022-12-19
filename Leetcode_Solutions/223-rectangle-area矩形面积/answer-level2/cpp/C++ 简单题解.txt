```C++ []
class Solution {
public:
    long overlap(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (min(C, G) > max(A, E) && min(D, H) > max(B, F))
            return (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        return 0;
    }
    long area(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) *  (y2 - y1);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return area(A, B, C, D) + area(E, F, G, H) - overlap(A, B, C, D, E, F, G, H);
        
    }
};
```

![image.png](https://pic.leetcode-cn.com/480ff85e96749fddaf2d02bfb965a9a7e9a9036cc2e8cc578a6ce9d0701421cf-image.png)
