### 解题思路
双百，代码也很简单
把矩形看成四条线，矩形交叉即为线的交替
每个rec[i]的值就是一条与坐标轴平行的线
本来想的是判断四个顶点坐标在不在另一个矩形里，然后借鉴了其他人的思路，改了下代码
判断线而不是判断点，学到了

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec1[2] > rec2[0] && rec1[0] < rec2[2] && rec1[3] > rec2[1] && rec1[1] < rec2[3]) {
        return true;
    } 
    return false;
}
```