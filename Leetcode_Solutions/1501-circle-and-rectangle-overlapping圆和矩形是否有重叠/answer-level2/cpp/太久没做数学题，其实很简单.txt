分类讨论一下圆心的位置，如果其垂线或水平线过矩形，那么两种情况。剩下一种情况是，四边形四个点是否在圆内，此时代入方程要是满足不等式则返回 true

```c++
class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        if (xc >= x1 && xc <= x2 && yc >= y1 && yc <= y2) return true;
        
        int up = yc + r, down = yc - r;
        int left = xc - r, right = xc + r;
        if (xc >= x1 && xc <= x2) {
            if (up >= y1 && down <= y2) return true;
        }
        if (yc >= y1 && yc <= y2) {
            if (right >= x1 && left <= x2) return true;
        }
        
        if (check(xc, yc, r, x1, y1) || check(xc, yc, r, x2, y1) || check(xc, yc, r, x1, y2) || check(xc, yc, r, x2, y2)) return true;
        return false;
    }
    
    bool check(int xc, int yc, int r, int x, int y) {
        float d = pow(x - xc, 2) + pow(y - yc, 2);
        if (d <= r * r) return true;
        return false;
    }
};
```