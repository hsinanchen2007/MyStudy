## 思路
首先判断是否有重合，然后分两种情况：
- 如果没有重合，则返回两个面积和
- 有重合，总面积 - 重合面积
### 代码
```c++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (D - B) * (C - A);
        int area2 = (H - F) * (G - E);
        int left = max(A, E);
        int right = min(C, G);
        int down = max(B, F);
        int up = min(D, H);
        if (left > right || down > up) {
            return area1 + area2;
        } 
        return area1 - (right - left) * (up - down) + area2;        
    }
};
```
