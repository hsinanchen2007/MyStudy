## 思路
两个矩形有重叠，则两个矩形的水平边和垂直边投影到x轴和y轴上有交集，对于水平边，如果两个矩形前面的点横坐标最小值大于后面两个点坐标最大值，则相交；同理，垂直边类似。

### 代码
时间复杂度：O(1)
空间复杂度：O(1)
```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) && min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
    }
};
```