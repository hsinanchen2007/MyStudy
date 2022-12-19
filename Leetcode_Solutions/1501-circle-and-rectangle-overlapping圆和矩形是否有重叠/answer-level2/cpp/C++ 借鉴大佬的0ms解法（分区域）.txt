```cpp
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // 条件1：圆心在矩形内
        if (x1 <= x_center && x_center <= x2 && y1 <= y_center && y_center <= y2) return true;
        // 条件2：圆心在矩形的上下左右四个区域
        else if (y_center > y2 && x1 <= x_center && x_center <= x2) //上下
            return radius >= y_center - y2;
        else if (y_center < y1 && x1 <= x_center && x_center <= x2)
            return radius >= y1 - y_center;
        else if (x_center < x1 && y1 <= y_center && y_center <= y2) //左右
            return radius >= x1 - x_center;
        else if (x_center > x2 && y1 <= y_center && y_center <= y2)
            return radius >= x_center - x2;
        //条件3：矩形的四个顶点是否在圆的内部
        else
        {
            int a = pow((x1 - x_center), 2) + pow((y1 - y_center), 2);
            int b = pow((x1 - x_center), 2) + pow((y2 - y_center), 2);
            int c = pow((x2 - x_center), 2) + pow((y1 - y_center), 2);
            int d = pow((x2 - x_center), 2) + pow((y2 - y_center), 2);
            int r = pow(radius, 2);
            return (a <= r || b <= r || c <= r || d <= r);
        }
    }
};
```