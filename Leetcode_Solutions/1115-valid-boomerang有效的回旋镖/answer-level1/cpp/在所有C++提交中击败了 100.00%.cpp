两点连成一条直线。因为2条线都共享一个点，只要两条线斜率相等，必为同一条直线。
```c++
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[2][1]-points[1][1])*(points[0][0]-points[1][0]) != (points[0][1]-points[1][1])*(points[2][0]-points[1][0]);
    }
};