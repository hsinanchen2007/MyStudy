### 解题思路
如果重叠那么X和Y都重叠

### 代码

```c
/*扫描线，从左到右扫描一个矩阵如果，扫描的数目为2那么没有相交，否则相交*/
#define Get_Edge(rec, xFlag)  (abs(rec[0 + xFlag] - rec[1 + xFlag]))
bool CheckEdgeOverLag(int* rec1, int* rec2, int xFlag){
    int x1 = rec1[0 + xFlag];
    int x2 = rec1[2 + xFlag];
    int x3 = rec2[0 + xFlag];
    int x4 = rec2[2 + xFlag];
    
    //printf("%d:%d-->%d:%d\n", x1, x2, x3,x4);
    if (x4 <= x1 || x3 >= x2){
        return false;
    }
    return true;
}
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    //检查X方向
    bool xFlag = CheckEdgeOverLag(rec1, rec2, 0);
    //printf("%d\n", xFlag);
    if (xFlag == false){
        return false;
    }
    //检查y方向
    bool yFlag = CheckEdgeOverLag(rec1, rec2, 1);
    if (yFlag == false){
        return false;
    }
    return true;
}
```