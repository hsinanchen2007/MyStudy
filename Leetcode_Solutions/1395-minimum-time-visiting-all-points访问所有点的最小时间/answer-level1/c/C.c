### 解题思路
此处撰写解题思路

### 代码

```c
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int result = 0;
    int i;
    for (i = 0; i < pointsSize - 1; i++) {
        result += abs(points[i+1][0] - points[i][0]) > abs(points[i+1][1] - points[i][1]) ?
                  abs(points[i+1][0] - points[i][0]) : abs(points[i+1][1] - points[i][1]);
    }

    return result;
}
```