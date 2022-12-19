```
class Solution {
    //将矩形的四周分为八个方位，分别判断圆在这八个方位的相交关系
   public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // 圆整个位于矩形的上、下、左、右四个位置
        if (y_center-radius>y2 || y_center+radius<y1 || x_center+radius<x1 || x_center-radius>x2)
            return false;
        // 圆心位于矩形的左上、左下、右上、右下四个位置，矩形四个顶点是否在圆内
        if(x_center<x1 && y_center>y2)
            return calDis(x_center, y_center, x1, y2, radius);
        if(x_center<x1 && y_center<y1)
            return calDis(x_center, y_center, x1, y1, radius);
        if(x_center>x2 && y_center>y2)
            return calDis(x_center, y_center, x2, y2, radius);
        if(x_center>x2 && y_center<y1)
            return calDis(x_center, y_center, x2, y1, radius);
 
        return true;
    }

    public boolean calDis(int x1, int y1, int x2, int y2,int r) {
        double dist=Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        return dist<r;
    }

}
```
