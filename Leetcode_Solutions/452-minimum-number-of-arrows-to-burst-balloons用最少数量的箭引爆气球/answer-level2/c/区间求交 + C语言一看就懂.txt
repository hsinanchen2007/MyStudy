### 解题思路
此处撰写解题思路

### 代码

```c

typedef struct {
    int l, r;
} Seg;

int cmp(const void *x, const void *y)
{
    return ((Seg *)x)->l > ((Seg *)y)->l ? 1 : -1;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

#define INF 0x7fffffff

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if (points == NULL || pointsColSize == NULL || pointsSize == 0) return 0;
    if (pointsSize == 1) return 1;
    Seg seg[10000];
    int res = pointsSize;
    for (int i = 0; i < pointsSize; i++) {
        seg[i].l = points[i][0];
        seg[i].r = points[i][1];
    }
    qsort(seg, pointsSize, sizeof(Seg), cmp);

    int x1 = -INF, y1 = -INF;
    for (int i = 0; i < pointsSize; i++) {
        //区间没有交集
        int x2 = seg[i].l, y2 = seg[i].r;
        if (x2 > y1) {
            x1 = x2, y1 = y2;
        } else {
            //否则必有交集
            x1 = x2, y1 = min(y1, y2);
            res--;
        }
    }
    return res;
}
```