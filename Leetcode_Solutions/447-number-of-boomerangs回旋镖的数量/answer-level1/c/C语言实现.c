C语言实现，执行用时:252 ms, 在所有 C 提交中击败了100.00%的用户。
```C []
int getDistance(int *a, int *b)
{
    return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    int mat_size = 500 * 500;
    int *mat = (int*)malloc(mat_size * sizeof(int));
    memset(mat, 0, mat_size * sizeof(int));
    int i, j, distance;
    for (i = 1; i < pointsSize; ++i){
        for (j = 0; j < i; ++j) {
            distance = getDistance(points[i], points[j]);
            mat[i * pointsSize + j] = distance;
            mat[j * pointsSize + i] = distance;
        }
    }
    int sum, res = 0;
    int *p = mat;
    for (i = 0; i < pointsSize; ++i){
        qsort(p, pointsSize, sizeof(int), cmp);
        sum = 1;
        for (j = 0; j < pointsSize - 1; ++j) {
            if (p[j] == p[j + 1]) {
                sum++;
            } else {
                if (sum > 1) {
                    res += sum * (sum - 1);
                    sum = 1;
                }
            }
        }
        if (sum > 1) res += sum * (sum - 1);
        p += pointsSize;
    }
    return res;
}
```
