### 解题思路
不妨设$rec_1$在$rec_2$下方，显然两个要重叠则$rec_1$的右上顶点要在$rec_2$的左下顶点上方，并且$rec_1$的左下顶点要在$rec_2$的右上顶点下方。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[2] > rec2[0] && rec1[3] > rec2[1])
        if(rec1[0] < rec2[2] && rec1[1] <= rec2[3])
            return 1;
        else
            return 0;
    else
        return 0;
}
```