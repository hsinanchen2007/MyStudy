### 解题思路
反面的种类比较少，可以取反面判断。

### 代码

```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][1], y1 = points[0][0];
        int x2 = points[1][1], y2 = points[1][0];
        int x3 = points[2][1], y3 = points[2][0];
        double k1 = fabs((y1 - y2) * 1.0 / (x1 - x2));
        double k2 = fabs((y2 - y3) * 1.0 / (x2 - x3));
        double k3 = fabs((y1 - y3) * 1.0 / (x1 - x3));
        if((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3) || k1 == k2 && k2 == k3)
            return false;
        else
            return true;
    }
};
```