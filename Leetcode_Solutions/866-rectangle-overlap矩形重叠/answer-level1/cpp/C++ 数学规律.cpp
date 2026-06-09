### 解题思路
如果相交的话，两个矩形的宽加起来后，一定是大于他们最远的点形成的矩形的宽。高也同理。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long width1 = rec1[2] - rec1[0];
        long width2 = rec2[2] - rec2[0];
        long height1 = rec1[3] - rec1[1];
        long height2 = rec2[3] - rec2[1];
        long crossWidth = max(rec1[2], rec2[2]) - min(rec1[0], rec2[0]);
        long crossHeight = max(rec1[3], rec2[3]) - min(rec1[1], rec2[1]);
        return crossWidth < (width1 + width2) && crossHeight < (height1 + height2);
    }
};
```