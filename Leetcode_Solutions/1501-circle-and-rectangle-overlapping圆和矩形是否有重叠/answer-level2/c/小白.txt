### 解题思路
1判断圆心是否在矩形m内
2判断4个角是否在矩形内
3把圆画成正方形 判断是否有重叠

### 代码

```c


bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){

    
    if(x_center>=x1&&x_center<=x2&&y_center>=y1&&y_center<=y2)
        return true;


    
    int a[4][2]={{x1,y1},{x2,y2},{x1,y2},{x2,y1}};
    for(int i=0;i<4;i++)
    {
        int x=abs(a[i][0]-x_center);
        int y=abs(a[i][1]-y_center);
        if(x*x+y*y<=radius*radius)
            return true;
    }


    int up = y_center + radius, down = y_center - radius;
    int left = x_center - radius, right = x_center + radius;
    if (x_center >= x1 && x_center <= x2) {
        if (up >= y1 && down <= y2) return true;
    }
    if (y_center >= y1 && y_center <= y2) {
        if (right >= x1 && left <= x2) return true;
    }

    
    return false;
}


```