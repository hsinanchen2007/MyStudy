```
struct Node {
    int index;
    int fight;
};

int CompareStruct(const void *a, const void *b)
{
    return (*(struct Node *)a).fight - (*(struct Node *)b).fight;
}

int *kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize)
{
    struct Node nodes[101] = {0};
    for (int i = 0; i < matSize; i++) {
        nodes[i].index = i;
        for (int j = 0; j < (*matColSize); j++) {
            if (mat[i][j] == 1) {
                nodes[i].fight++;
            }
        }
    }
    qsort(nodes, matSize, sizeof(struct Node), CompareStruct);
    int *res = (int *)malloc(k * sizeof(int));
    memset(res, 0, k * sizeof(int));
    (*returnSize) = k;
    for (int i = 0; i < k; i++) {
        res[i] = nodes[i].index;
    }
    return res;
}
```
