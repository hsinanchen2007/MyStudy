### 解题思路
矩阵对角i线 判定两个临界条件  沿x方向 与 沿y方向
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec2[2] <= rec1[0]) {
        return false;
    }
    if (rec2[0] >= rec1[2]) {
        return false;
    }
    if (rec2[1] >= rec1[3]) {
        return false;
    }
    if (rec2[3] <= rec1[1]) {
        return false;
    }
    return true;
}

```