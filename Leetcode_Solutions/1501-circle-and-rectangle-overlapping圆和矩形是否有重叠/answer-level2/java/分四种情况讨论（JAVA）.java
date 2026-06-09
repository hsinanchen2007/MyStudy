```
class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x1 <= x_center && x2 >= x_center && y1 <= y_center && y2 >= y_center){
            return true;
        }//第一种情况，圆心在矩形内部，必然有重合区域
        else if(x1 <= x_center && x2 >= x_center){
            int y_dis = Math.min(Math.abs(y_center - y1), Math.abs(y_center - y2));
            return (y_dis <=radius);
        }//第二种情况，圆心在矩形外部，且x_center在矩形的x1和x2之间
        else if(y1 <= y_center && y2 >= y_center){
            int x_dis = Math.min(Math.abs(x_center - x1), Math.abs(x_center - x2));
            return (x_dis <= radius);y
        }//第三种情况，圆心在矩形外部，且y_center在矩形的y1和y2之间

        //第四种情况，圆心在矩形外部，且y_center不在y1、y2之间，x_center不在x1、x2之间
        double disd = Math.min(dis(x_center, y_center, x2, y2),dis(x_center, y_center, x1, y1));
        disd = Math.min(disd, dis(x_center, y_center, x1, y2));
        disd = Math.min(disd, dis(x_center, y_center, x2, y1));
        return disd <= radius;
    }
    public double dis(int x1, int y1, int x2, int y2){
        return Math.sqrt(Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2));
    }
}
```
