### 解题思路
主要思想是如果两个矩形长度之和大于最大横坐标和最小横坐标之差，且两个矩形宽度之和大于最大纵坐标和最小纵坐标之差，那么就重叠，可以用一行代码表示。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return abs(max(max(rec1[0],rec1[2]),max(rec2[0],rec2[2]))-min(min(rec1[0],rec1[2]),min(rec2[0],rec2[2])))-abs(rec1[0]-rec1[2])-abs(rec2[0]-rec2[2])<0&&abs(max(max(rec1[1],rec1[3]),max(rec2[1],rec2[3]))-min(min(rec1[1],rec1[3]),min(rec2[1],rec2[3])))-abs(rec1[1]-rec1[3])-abs(rec2[1]-rec2[3])<0;
    }
};
```