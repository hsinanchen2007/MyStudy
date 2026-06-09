### 解题思路
1. 检验三点相异
2. 检验三点不共线(x1*y2 - x2*y1 != 0)

### 代码

```c
bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    if (points[0][0] == points[1][0] && points[0][1] == points[1][1] ) return false;
    if (points[0][0] == points[2][0] && points[0][1] == points[2][1] ) return false;
    if (points[1][0] == points[2][0] && points[1][1] == points[2][1] ) return false;

    int dx_1 = points[0][0] - points[1][0];
    int dy_1 = points[0][1] - points[1][1];
    int dx_2 = points[0][0] - points[2][0];
    int dy_2 = points[0][1] - points[2][1];
    
    return dx_1*dy_2 - dx_2*dy_1!=0;
}
```