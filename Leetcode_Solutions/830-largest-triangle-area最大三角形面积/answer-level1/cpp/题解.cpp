### 解题思路
任取vector中三点A(a1,a2),B(b1,b2),C(c1,c2)
面积计算简化为area = abs( (a1-b1)(b2-c2) - (a2-b2)(b1-c1) )
公式由向量叉乘得，area值为面积两倍
### 代码

```cpp
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int size = points.size();
        int area2 = 0;
        int newArea2 = 0;
        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; j++) {
                for (int k = j + 1; k < size; k++) {
                    newArea2 = abs(
                                (points[i][0] - points[j][0]) * (points[j][1] - points[k][1]) 
                                - (points[i][1] - points[j][1]) * (points[j][0] - points[k][0]) 
                                );
                    if (area2 < newArea2){
                        area2 = newArea2;
                    }
                }
            }
        }
        return area2 / 2.0;
    }
};
```