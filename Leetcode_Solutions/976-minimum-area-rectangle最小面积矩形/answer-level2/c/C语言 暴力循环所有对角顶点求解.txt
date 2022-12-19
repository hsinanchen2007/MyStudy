C语言解法，将序列从左下往右上顺序排列，然后循环计算各个对角顶点之间的面积，取最小值即可。


```
typedef struct{
    int x;
    int y;
}Dot;

int cmpDot(const void* a, const void* b)
{
    Dot arg1 = *(const Dot *)a;
    Dot arg2 = *(const Dot *)b;
    if(arg1.x != arg2.x){
        return arg1.x - arg2.x;
    }
    return arg1.y - arg2.y;
}

Dot dots[501];

bool isExist(int i, int j, int x, int y)
{
    int mid;
    mid = (j - i)/2 + i;
    if(i > j){
        return false;
    }
    if(dots[mid].x == x && dots[mid].y == y) {
        return true;
    }

    if(dots[mid].x > x || (dots[mid].x == x && dots[mid].y > y)) {
        return isExist(i, mid-1, x,y);
    } 
    return isExist(mid + 1, j, x, y);
}

int minAreaRect(int** points, int pointsSize, int* pointsColSize)
{
    int i, j;
    int tmp;
    int result = INT_MAX;
    memset(dots, 0, sizeof(dots));
    for(i = 0; i < pointsSize; i++) {
        dots[i].x = points[i][0];
        dots[i].y = points[i][1];
    }
    qsort(dots, pointsSize, sizeof(Dot), cmpDot);

    for(i = 0; i < pointsSize; i++) {
        for(j = i+1; j < pointsSize;j++) {
            
            if(dots[i].x == dots[j].x || dots[i].y == dots[j].y) {
                continue;
            }
            tmp = abs((dots[j].x - dots[i].x) * (dots[j].y - dots[i].y));

            if( tmp > result) {
                continue;
            }
            if(isExist(0, pointsSize, dots[i].x, dots[j].y) && isExist(0, pointsSize, dots[j].x, dots[i].y)) {
                result = tmp;

            }
        }
    }

    return result == INT_MAX ? 0 : result;
}
```


