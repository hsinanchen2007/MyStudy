### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[2]<=rec1[0]||rec2[1]>=rec1[3]||rec2[3]<=rec1[1]||rec2[0]>=rec1[2]);
    }
};
```将矩形1放入坐标系中，用x=x1,x2;y=y1,y2很容易可以画出与其不重叠的区域；四个条件只要满足一个就不会重叠