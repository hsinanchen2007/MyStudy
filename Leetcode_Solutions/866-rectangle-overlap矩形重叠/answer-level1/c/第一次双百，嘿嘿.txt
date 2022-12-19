### 
类似两个圆求相对位置

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    double i,j;
    double m,n;
    i = rec1[0] + (rec1[2] - rec1[0]) / 2;
    j = rec1[1] + (rec1[3] - rec1[1]) / 2;
    m = rec2[0] + (rec2[2] - rec2[0]) / 2;
    n = rec2[1] + (rec2[3] - rec2[1]) / 2;
    double L1,L2,H1,H2;
    L1 = rec1[2] - rec1[0];
    H1 = rec1[3] - rec1[1];
    L2 = rec2[2] - rec2[0];
    H2 = rec2[3] - rec2[1];
    if ((fabs(m - i) * 2) < (L1 + L2)) {
        if ((fabs(n - j) * 2) < (H1 + H2)) {
            return true;
        }
    }
    return false;
}
```