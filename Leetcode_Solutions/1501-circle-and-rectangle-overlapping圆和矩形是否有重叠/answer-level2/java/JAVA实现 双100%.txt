**解题步骤如注释所示**
```java
    public  boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        //判断圆是否在矩形内
        if (x1 <= x_center && x2 >= x_center && y1 <= y_center && y2 >= y_center)
            return true;
        //判断矩形的四个点是否在圆内
        if (Math.sqrt((x1 - x_center) * (x1 - x_center) + (y1 - y_center) * (y1 - y_center)) <= radius)
            return true;
        if (Math.sqrt((x1 - x_center) * (x1 - x_center) + (y2 - y_center) * (y2 - y_center)) <= radius)
            return true;
        if (Math.sqrt((x2 - x_center) * (x2 - x_center) + (y1 - y_center) * (y1 - y_center)) <= radius)
            return true;
        if (Math.sqrt((x2 - x_center) * (x2 - x_center) + (y2 - y_center) * (y2 - y_center)) <= radius)
            return true;
        //矩形的点不在圆内,但矩形与圆相交的情况
        if (y1 < y_center && y2 > y_center && ((Math.abs(x1 - x_center) <=radius || Math.abs(x2 - x_center) <=radius)))
            return true;
        if (x1 < x_center && x2 > x_center && ((Math.abs(y1 - y_center) <=radius || Math.abs(y2 - y_center) <=radius)))
            return true;
        return false;
    }
```