![image.png](https://pic.leetcode-cn.com/18bccff51511fd419fe008ca57b48f5b5791bb3b45e4ad380afae98a6f2cb4b6-image.png)



```
public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // 圆整体在在矩形 上、下、左、右 位置的且不相交情况
        if (x_center + radius < x1 || x_center - radius > x2 || y_center + radius < y1 || y_center - radius > y2) {
            return false;
        }

        if (x_center < x1) {
            if(y_center>y2){
                // 圆心在左上范围 判断是否相交
                return dist(x_center, y_center, x1, y2, radius);
            }
            if(y_center<y1){
                // 圆心在左下范围 判断是否相交
                return dist(x_center, y_center, x1, y1, radius);
            }
        }
        if (x_center > x2) {
            if(y_center>y2){
                // 圆心在右上范围 判断是否相交
                return dist(x_center, y_center, x2, y2, radius);
            }
            if(y_center<y1){
                // 圆心右下范围 判断是否相交
                return dist(x_center, y_center, x2, y1, radius);
            }
        }

        return true;
    }

    public boolean dist(int x1, int y1, int x2, int y2,int r) {
       double dist =  Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        return dist<r;
    }
```
