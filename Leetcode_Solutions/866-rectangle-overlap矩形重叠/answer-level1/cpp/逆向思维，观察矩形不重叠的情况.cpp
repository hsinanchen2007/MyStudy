### 解题思路
当两矩形不重叠时，投影到x轴,y轴上，一定满足左边矩形x2<=右边矩形x1，或者上边矩形y1>=下边矩形y2
注意两个矩形都有可能位于左边、上边。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]||rec1[1]>=rec2[3]||rec2[1]>=rec1[3])
            return false;
        else
            return true;
    }
};
```