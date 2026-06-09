```
    /*
    把正方形划分为9个区域 根据圆心位置来划分
           1.当圆心在内部时 也相交
           2.当圆心在上下左右时 若圆心与某边的距离<=r 相交
           3.当圆心在其余位置时 若存在圆心与某点距离 <= r 相交
           
    */
    int get(int x1,int y1, int x2, int y2){//获得两点距离
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
    bool checkOverlap(int r, int x, int y, int x1, int y1, int x2, int y2) {
        if(x>=x1&&x<=x2 && y>=y1&&y<=y2) return true;//圆心在内部
        if(y>=y1&&y<=y2&&x<x1&&x1-x<=r||y>=y1&&y<=y2&&x>x2&&x-x2<=r||x>=x1&&x<=x2&&y>y2&&y-y2<=r
                        ||x>=x1&&x<=x2&&y<y1&&y1-y<=r) return true;//圆在正方形的 左 右 上 下 时的相交条件
        for(int i : {x1,x2}){//在其余位置时
            for(int j : {y1,y2}){
                if(get(x,y,i,j) <= r*r) return true;
            }
        }
        return false;
    }
```
