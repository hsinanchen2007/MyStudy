### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1.size()==0 || rec2.size() == 0)return false;
        int x11 = rec1[0],y11 = rec1[1],x12 = rec1[2],y12 = rec1[3];
        int x21 = rec2[0],y21 = rec2[1],x22 = rec2[2],y22 = rec2[3];
        if(x11>=x12||y11>=y12) return false;
        if(x21>=x22||y21>=y22) return false;
        if(x11<x22&&y11<y22&&x21<x12&&y21<y12)return true;
        return false;
    }
};
```