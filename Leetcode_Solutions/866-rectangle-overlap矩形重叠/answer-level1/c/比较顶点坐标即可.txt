### 解题思路
数组是对角线的两个点的坐标，后者坐标一定比前者大。
比较矩形2的前者与矩形1的后者，对应矩形1在矩形2的左方或下方。
比较矩形1的前者与矩形2的后者，对应矩形2在矩形1的左方或下方。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[2]<=rec2[0] || rec1[3]<=rec2[1])
        return false;
    if(rec2[2]<=rec1[0] || rec2[3]<=rec1[1])
        return false;
    return true;
}
```