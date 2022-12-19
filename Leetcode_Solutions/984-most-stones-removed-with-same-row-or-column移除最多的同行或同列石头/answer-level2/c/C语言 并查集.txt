主要看石头相同行列合并之后，剩余几个集合，每个集合必然最少要剩1个石头，因此move最多的总数应该等于
stonesSize - 集合数
操作比较简单，直接创建1个从0到stonesSize-1序号的石子集合，然后只要行标相同就合并，列标相同就合并。
最终检查合并后的集合set中有多少个集合，然后求得最终结果。
```
int* MakeSet(int n)
{
    int *set = calloc((unsigned int)n, sizeof(int));
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }
    return set;
}
int Find(int a, int *set)
{
    int m = a;
    while (set[m] != m) {
        set[m] = set[set[m]];
        m = set[m];
    }
    return m;
}
void Merge(int a, int b, int *set)
{
    int m = Find(a, set);
    int n = Find(b, set);
    if (m == n) {
        return;
    }
    set[n] = m;
    return;
}
void MergeCol(int *set, int **stones, int stonesSize)
{
    for (int i = 0; i < stonesSize; i++) {
        for (int j = i + 1; j < stonesSize; j++) {
            if ((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])) {
                Merge(i, j, set);
            }
        }
    }
}
int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int *set = NULL, *newSet = NULL, newSetCnt = 0;
    if ((stonesSize == 0) || (stones == NULL)) {
        return 0;
    }
    set = MakeSet(stonesSize);
    MergeCol(set, stones, stonesSize);
    newSet = calloc((unsigned int)stonesSize, sizeof(int));
    for (int k = 0; k < stonesSize; k++) {
        newSet[Find(k, set)] = 1;
    }
    for (int r = 0; r < stonesSize; r++) {
        if (newSet[r] == 1) {
            newSetCnt++;
        }
    }
    free(set);
    free(newSet);
    return stonesSize - newSetCnt;
}
```
