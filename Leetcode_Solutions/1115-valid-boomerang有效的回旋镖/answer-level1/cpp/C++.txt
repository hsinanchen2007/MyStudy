### 解题思路
计算两点的所在直线的斜率是否相同即可

### 代码

```cpp
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //计算两点的所在直线的斜率是否相同即可
        //计算第1，2点所在直线的斜率
        // int k1 = (points[0][1] - points[1][1]) / (points[0][0] - points[1][0]);
        // //计算第2，3点所在直线斜率
        // int k2 = (points[1][1] - points[2][1]) / (points[1][0] - points[2][0]);

        return (points[0][1] - points[1][1]) * (points[1][0] - points[2][0]) != (points[0][0] - points[1][0]) * (points[1][1] - points[2][1])? true:false;
    }
};
```