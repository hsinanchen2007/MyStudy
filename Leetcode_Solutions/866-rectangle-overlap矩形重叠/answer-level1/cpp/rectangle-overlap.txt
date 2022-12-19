### 解题思路
两个矩阵如果要有重合，那么在x轴与y轴上的映射一定要有重合部分，所以我们可以通过判断x,y轴上矩阵的映射是否相交进行判断，如果x or y轴上不相交，那么它们就不相交

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2]<=rec2[0]||rec2[2]<=rec1[0]) return false;
        if(rec1[3]<=rec2[1]||rec2[3]<=rec1[1]) return false;
        return true;
    }
};
```