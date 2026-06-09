```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct node {
    int a;
    int b;
    int s;
};
bool CheckParam(int** points, int pointsSize, int* pointsColSize, int K)
{
    if (!points || !pointsColSize) {
        return false;
    }
    if (!pointsSize || !K) {
        return false;
    }
    return true;
}
int CalcDistance(int a, int b)
{
    return a * a + b * b;
}
int CompareStruct(const void *a, const void *b)
{
    return (*(struct node*)a).s - (*(struct node*)b).s;
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes)
{
    bool check = false;

    check = CheckParam(points, pointsSize, pointsColSize, K);
    if (!check) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        printf("param invalid\n");
        return NULL;
    }
    struct node nodes[10 *1024] = {0};

    for (int i = 0; i < pointsSize; i++) {
        nodes[i].a = points[i][0];
        nodes[i].b = points[i][1];
        nodes[i].s = CalcDistance(points[i][0], points[i][1]);
    }
    qsort(&nodes, pointsSize, sizeof(struct node), CompareStruct);

    int **res = (int **)malloc(K * sizeof(int *));

    memset(res, 0, K * sizeof(int *));
    for (int i = 0; i < K; i++) {
        res[i] = (int *)malloc(2 * sizeof(int));
        res[i][0] = nodes[i].a;
        res[i][1] = nodes[i].b;
    }
    int *resCol = malloc(K * sizeof(int));

    memset(resCol, 0, K * sizeof(int));
    for (int i = 0; i < K; i++) {
        resCol[i] = 2;
    }
    *returnColumnSizes = resCol;
    *returnSize = K;
    return res;
}
```
