### 解题思路
反向思维，找不不想交的情况，其他情况一定都是相交的

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    bool rlt = true;
    int rec1x1 = rec1[0];
    int rec1y1 = rec1[1];
    int rec1x2 = rec1[2];
    int rec1y2 = rec1[3];

    int rec2x1 = rec2[0];
    int rec2y1 = rec2[1];
    int rec2x2 = rec2[2];
    int rec2y2 = rec2[3];

    if ((rec2x1 >= rec1x2) || (rec1x1 >= rec2x2)) {
        rlt = false;
    }
    else if ((rec2y1 >= rec1y2) || (rec1y1 >= rec2y2)) {
        rlt = false;
    }
    return rlt;
}
```