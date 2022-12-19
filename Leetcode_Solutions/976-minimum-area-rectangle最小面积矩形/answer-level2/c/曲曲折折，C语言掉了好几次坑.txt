
```
/*
  思路，如果存在对角线上的点A和B，那么看是否同时存在C和D；若是那么求这个矩形的面积
  C(x1,y2)     B(x2,y2)

  A(x1,y1)     D(x2,y1)

*/
#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool HavePoint(int** points, int pointsSize, int x, int y) {
    int i;
    for (i = 0; i < pointsSize; i++) {
        if (x == points[i][0] && y == points[i][1]) {
            return true;
        }
    }
    return false;
}

int minAreaRect(int** points, int pointsSize, int* pointsColSize) { // 最后一个参数没有用
    int min = INT_MAX;
    bool haveRect = false; // 这个标志位一定不可少，对应题目中描述如果没有矩形就返回0

    int i, j;
    for (i = 0; i < pointsSize; i++) {
        for (j = 1; j < pointsSize; j++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            if (x1 != x2 && y1 != y2) { // 先找到对角线上的2个点
                int curArea = abs(x1 - x2) * abs(y1 - y2);
                // 先不判断是否能组成矩形，先看这2个点是否对应的矩形太大，如果太大直接continue
                // 这样就避免了不必要的HavePoint动作，相比求面积，HavePoint耗时过大
                if (curArea >= min) {
                    continue;
                }
                if (HavePoint(points, pointsSize, x1, y2) == true && HavePoint(points, pointsSize, x2, y1) == true) {
                    haveRect = true;
                    min = MIN(min, curArea);
                }
            }
        }
    }
    return haveRect == false ? 0 : min;
}
```
