### 解题思路
直接上代码

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int overlap[4];
    overlap[0] = rec1[0] > rec2[0] ? rec1[0] : rec2[0];
    overlap[1] = rec1[1] > rec2[1] ? rec1[1] : rec2[1];
    overlap[2] = rec1[2] < rec2[2] ? rec1[2] : rec2[2];
    overlap[3] = rec1[3] < rec2[3] ? rec1[3] : rec2[3];
    return overlap[0] < overlap[2] && overlap[1] < overlap[3];
}
```