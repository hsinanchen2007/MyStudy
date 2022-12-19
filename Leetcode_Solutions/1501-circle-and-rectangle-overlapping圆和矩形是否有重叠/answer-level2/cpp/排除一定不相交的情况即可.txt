简单来说就是拿圆形绕矩形。
在上下左右四个方向上，以上边为例，圆形的最低端都比矩形的最顶端高的话，一定不会相交，其他三个方向同理。
四个角的情况稍微复杂点，如果圆形在矩形的左上角，那么圆形的最左端和最顶端一定不在矩形的坐标范围内，再判断矩形的左上角顶点是否在圆形里面。
排除了上面八种一定不相交的情况，剩下的就一定会相交，返回true即可。
```
class Solution {
public:
    long long dis(long long x1,long long y1,long long x2,long long y2){
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int left_most=x_center-radius,right_most=x_center+radius,top_most=y_center+radius,button_most=y_center-radius;
        if(left_most>x2)
            return false;
        if(right_most<x1)
            return false;
        if(top_most<y1)
            return false;
        if(button_most>y2)
            return false;
        if(left_most<x1&&top_most>y2){
            if(radius<dis(x1,y2,x_center,y_center))
                return false;
        }
        else if(right_most>x2&&top_most>y2){
            if(radius<dis(x2,y2,x_center,y_center))
                return false;
        }
        else if(left_most<x1&&button_most<y1){
            if(radius<dis(x1,y1,x_center,y_center))
                return false;
        }
        else if(right_most>x2&&button_most<y1){
            if(radius<dis(x2,y1,x_center,y_center))
                return false;
        }
        return true;
    }
};
```
