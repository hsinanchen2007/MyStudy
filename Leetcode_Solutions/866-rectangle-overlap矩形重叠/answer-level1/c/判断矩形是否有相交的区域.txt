### 解题思路
此处撰写解题思路

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){

    //确定两个矩形的四个坐标
    int x11 = rec1[0];
    int x12 = rec1[2];
    int y11 = rec1[1];
    int y12 = rec1[3];

    int x21 = rec2[0];
    int x22 = rec2[2];
    int y21 = rec2[1];
    int y22 = rec2[3];

    //逆向思维，寻找矩形不相交的条件
    //只要保证矩形所在的X轴 或者Y轴不相交，就能保证两个矩形不相交
    if ((x11<=x21 && x11<=x22 && x12<=x21 && x12<=x22) || 
    (x11>=x21 && x11>=x22 && x12>=x21 && x12>=x22) ||
    (y11<=y21 && y11<=y22 && y12<=y21 && y12<=y22) ||
    (y11>=y21 && y11>=y22 && y12>=y21 && y12>=y22)) {
        return false;
    } else {
        return true;
    }

    return false;
}
```