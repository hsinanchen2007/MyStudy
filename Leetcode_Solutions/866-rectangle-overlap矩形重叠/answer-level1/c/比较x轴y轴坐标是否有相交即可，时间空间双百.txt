比较x轴y轴坐标是否有相交即可
```
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec1[2] > rec2[0] && rec1[0] < rec2[2] && rec1[3] > rec2[1] && rec1[1] < rec2[3]) {
        return true;
    } else if (rec2[2] > rec1[0] && rec2[0] < rec1[2] && rec2[3] > rec1[1] && rec2[1] < rec1[3]) {
        return true;
    }
    return false;
}

