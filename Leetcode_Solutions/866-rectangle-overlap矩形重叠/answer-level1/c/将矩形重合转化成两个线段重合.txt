两个矩形重合，等价于水平方向的线段重合，**并且**竖直方向的线段重合。
因此将矩形重合问题分解为线段重合问题。

对于两个线段，分别设为[x1,x2]和[x3,x4]，那么重合条件为：
1. x3 <= x1, x4 > x1
2. x1 < x3 < x2, x4任意
```
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    bool isLineOverlap(int* line1, int* line2);
    int line1[2] = {rec1[0],rec1[2]}, line2[2] = {rec2[0],rec2[2]};
    int line3[2] = {rec1[1],rec1[3]}, line4[2] = {rec2[1],rec2[3]};
    if(isLineOverlap(line1,line2) && isLineOverlap(line3,line4))    return true;
    else return false;
}

bool isLineOverlap(int* line1, int* line2){
    int x1 = line1[0], x2 = line1[1], x3 = line2[0], x4 = line2[1];
    if(x3 <= x1 && x4 > x1 || x3 > x1 && x3 < x2)   return true;
    else return false;
}
```
