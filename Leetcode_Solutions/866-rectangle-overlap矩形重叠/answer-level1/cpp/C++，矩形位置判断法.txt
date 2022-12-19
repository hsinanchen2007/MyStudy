### 解题思路
比较矩形1和矩形2是否重叠，可以转换为判断矩形1和矩形2是否未重叠。
矩形1如果和矩形2未重叠，则矩形1要么在矩形的左边，要么在矩形的右边，要么在矩形的上边，要么在矩形的下边。
然而这些条件通过矩形的坐标能够很轻松的判断出来

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool flag = !(rec1[2] <= rec2[0] || 
                      rec1[0] >= rec2[2] || 
                      rec1[1] >= rec2[3] || 
                      rec1[3] <= rec2[1]);
        return flag;
    }
};
```