这道题做法很多种，当然用正方形的区域划分比较好做，我们考虑圆心是否在正方形内，正方形的边区域内，以及正方形的角区域内。如果圆心在正方形内部肯定true。如果是在边区域上只要判断圆心和正方形中心的距离是否小于等于半径加二分之一边长。如果在角区域就直接判断圆心到四个顶点距离是否有小于等于半径的。下面是双百代码：
```
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int a,b,c,d,r;
        if (x_center<=x2 && x_center>=x1 && y_center<=y2 && y_center>=y1)
            return true;
        else if (x_center<=x2 && x_center>=x1 && y_center>=y2 )
            return (y_center-radius<=y2);
        else if (x_center<=x2 && x_center>=x1 && y_center<=y1 )
            return (y_center+radius>=y1);
        else if (y_center<=y2 && y_center>=y1 && x_center>=x2 )
            return (x_center-radius<=x2);
        else if (y_center<=y2 && y_center>=y1 && x_center<=x1 )
            return (x_center+radius>=x1);
        else 
        {
            a=pow((x1-x_center),2)+pow((y1-y_center),2);
            b=pow((x1-x_center),2)+pow((y2-y_center),2);
            c=pow((x2-x_center),2)+pow((y1-y_center),2);
            d=pow((x2-x_center),2)+pow((y2-y_center),2);
            r=pow(radius,2);
            return (a<=r || b<=r || c<=r || d<=r);
        }
    }
};
```
