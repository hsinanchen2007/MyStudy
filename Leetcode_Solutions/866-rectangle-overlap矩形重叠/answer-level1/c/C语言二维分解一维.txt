### 解题思路
矩形投影到横纵坐标上，只有横纵坐标都重合，矩形才重合。
### 代码

```c
#define PRINTF // printf
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int bRet = false;
    if ((rec1 == NULL) || (rec2 == NULL)) {
        goto END;
    }
    int rowDup = 0, colDup = 0;
    if (((rec2[0] > rec1[0]) && (rec2[0] < rec1[2])) || \
        ((rec2[2] > rec1[0]) && (rec2[2] < rec1[2])) || \
        ((rec2[0] >= rec1[0]) && (rec2[2] <= rec1[2])) || \
        ((rec1[0] >= rec2[0]) && (rec1[2] <= rec2[2]))){
        rowDup = 1;
    }
    PRINTF("%d %d %d %d\n",rec1[0], rec2[0], rec1[2], rec2[2]);
    if (((rec2[1] > rec1[1]) && (rec2[1] < rec1[3])) || \
        ((rec2[3] > rec1[1]) && (rec2[3] < rec1[3])) || \
        ((rec2[1] >= rec1[1]) && (rec2[3] <= rec1[3])) || \
        ((rec1[1] >= rec2[1]) && (rec1[3] <= rec2[3]))){
        colDup = 1;
    }
    PRINTF("%d %d %d %d\n",rec1[1], rec2[1], rec1[3], rec2[3]);
    if ((rowDup == 1) && (colDup == 1)) {
        bRet = true;
    }
END:
    return bRet;

}
```