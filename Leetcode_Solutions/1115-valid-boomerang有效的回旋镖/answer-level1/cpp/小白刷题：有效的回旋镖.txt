二维向量外积不为0，则两向量共线

代码：
```
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[1][0] - points[0][0];
        int x2 = points[2][0] - points[0][0];
        int y1 = points[1][1] - points[0][1];
        int y2 = points[2][1] - points[0][1];
        return x1 * y2 != x2 * y1;
    }
};
```
