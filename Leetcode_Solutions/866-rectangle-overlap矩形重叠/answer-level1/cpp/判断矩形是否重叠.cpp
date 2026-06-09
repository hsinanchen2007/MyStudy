### 解题思路
官方答案是通过判断矩形2与1是否在左右上下四个方向上没重叠的情况，然后取反
另一种是分别在x、y方向上投影矩阵，当两个投影线段相交时说明重叠

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[1]>=rec1[3]
                || rec2[3]<=rec1[1]
                || rec2[2]<= rec1[0]
                || rec2[0]>= rec1[2]);
    }
};
```