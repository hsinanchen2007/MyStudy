```
int compare(const void *a, const void *b)
{
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;
    if (p1[1] != p2[1]) {
        return p1[1] - p2[1];
    }
    return p1[0] - p2[0];
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    if (pointsSize < 2) {
        return pointsSize;
    }

    int count = 1;
    qsort(points, pointsSize, sizeof(int *), compare);
    int left = points[0][1];
    int i = 1;
    while (i < pointsSize) {
        int right = points[i][0];
        if (left < right) {
            count++;
            left = points[i][1];
        }
        i++;
    }

    return count;
}
```
