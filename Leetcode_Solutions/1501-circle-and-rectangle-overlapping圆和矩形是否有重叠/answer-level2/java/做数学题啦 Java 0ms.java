一个数学题啦
(x, y) is such a point that belongs to the circle and the rectangle at the same time
-> x1 <= x <= x2, y1 <= y <= y2 (in rectangle)
-> (x - xc)^2 + (y - yc)^2 <= r^2 (in circle)
Let Xi = x - xc, Yi = y - yc
We want Xi^2 + Yi^2 <= radius^2
+ Minimal absolute value of Xi = min(|x1 - xc|, |x2 - xc|) or 0 (if xc in [x1, x2])
+ Minimal absolute value of Yi = min(|y1 - xc|, |y2 - yc|) or 0 (if yc in [y1, y2])

-> If the sum of the squre of two minimal values is no larger than the squre of radius, (x, y) exits.

```java
class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        //(x, y) is such a point
        //x1 <= x <= x2
        //y1 <= y <= y2
        //(x - xc)^2 + (y - yc)^2 <= r^2
        //xi = x - xc, yi = y - yc
        int xi_min, yi_min;
        if(x1 < x_center && x2 > x_center){
            xi_min = 0;
        }else{
            xi_min = Math.min(Math.abs(x1 - x_center), Math.abs(x2 - x_center));
        }
        if(y1 < y_center && y2 > y_center){
            yi_min = 0;
        }else{
            yi_min = Math.min(Math.abs(y1 - y_center), Math.abs(y2 - y_center));
        }

        if(Math.pow(xi_min, 2) + Math.pow(yi_min, 2) <= Math.pow(radius, 2)){
            return true;
        }else{
            return false;
        }
        
    }
}
```
