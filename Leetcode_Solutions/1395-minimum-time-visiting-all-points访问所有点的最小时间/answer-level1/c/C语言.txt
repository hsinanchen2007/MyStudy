```
int calMinDistence(int *x, int xsize, int *y, int ysize) {
    if (xsize != ysize) {
        return -1;
    }
    int count = 0;
    int a[2], b[2];
    for(int i = 0; i < 2; i++) {
        a[i] = x[i];
        b[i] = y[i];
    }
    if (a[0] != b[0] && a[1] != b[1]) {
        if (a[0] < b[0] && a[1] < b[1]) {  // +1  +1
            while (a[0] != b[0] && a[1] != b[1]) {
                a[0]++;
                a[1]++;
                count++;
            }
        } else if (a[0] < b[0] && a[1] > b[1]) {  // +1 -1
            while (a[0] != b[0] && a[1] != b[1]) {
                a[0]++;
                a[1]--;
                count++;
            }
        } else if (a[0] > b[0] && a[1] < b[1]) {   // -1  +1
            while (a[0] != b[0] && a[1] != b[1]) {
                a[0]--;
                a[1]++;
                count++;
            }
        } else {  //  -1  -1
            while (a[0] != b[0] && a[1] != b[1]) {
                a[0]--;
                a[1]--;
                count++;
            }
        }
    }
    if (a[0] == b[0]) {
        if (a[1] < b[1]) {
            count += b[1] - a[1];
        } else {
            count += a[1] - b[1];
        }
    }
    if (a[1] == b[1]) {
        if (a[0] < b[0]) {
            count += b[0] - a[0];
        } else {
            count += a[0] - b[0];
        }
    }
    return count;
}
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
    int ret = 0;
    for(int i = 0, j = 1; j < pointsSize; i++, j++) {
        ret += calMinDistence(points[i], pointsColSize[i], points[j], pointsColSize[j]);
    }
    return ret;
}
```
写完看题解才知道原来有切比雪夫距离这种神奇的东西，原谅我数学渣渣
