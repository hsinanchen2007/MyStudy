![截图.PNG](https://pic.leetcode-cn.com/30abdba22f291c2c2e42d05041aa416c695d60e8f3db310ba9e1abdc36f52897-%E6%88%AA%E5%9B%BE.PNG)

```
#define MAX_NUM 1000
static int g_hash[MAX_NUM][2] = {0};
static int g_hashCnt = 0;

static void AddHash(int a, int b)
{
    int i;
    
    if (g_hashCnt == 0) {
        g_hash[0][0] = a;
        g_hash[0][1] = b;
        g_hashCnt++;
        return;
    }
    if (g_hash[g_hashCnt - 1][0] == a) {
        if (b > g_hash[g_hashCnt - 1][1]) {
            g_hash[g_hashCnt - 1][1] = b;
        }
        return;
    } else {
        if (a <= g_hash[g_hashCnt - 1][1]) {
            if (g_hash[g_hashCnt - 1][1] < b) {
                g_hash[g_hashCnt - 1][1] = b;
            }
            return;
        }
    }
    g_hash[g_hashCnt][0] = a;
    g_hash[g_hashCnt][1] = b;
    g_hashCnt++;
}

static void ResetHash(void)
{
    g_hashCnt = 0;
}

static int compare(const void *a, const void *b)
{
    int *aa = *(int **)a;
    int *bb = *(int **)b;

    if (aa[0] == bb[0]) {
        return (aa[1] - bb[1]);
    } else {
        return (aa[0] - bb[0]);
    }
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int **result = NULL;
    
    if (intervals == NULL || intervalsSize == 0 || intervalsColSize == NULL) {
        *returnSize = 0;
        return intervals;
    }
    ResetHash();
    
    qsort(intervals, intervalsSize, sizeof(int) * 2, compare);
    for (i = 0; i < intervalsSize; i++) {
        AddHash(intervals[i][0], intervals[i][1]);
    }
    
    for (i = 0; i < g_hashCnt; i++) {
        intervals[i][0] = g_hash[i][0];
        intervals[i][1] = g_hash[i][1];
        
    }
    
    *returnSize = g_hashCnt;
    *returnColumnSizes = intervalsColSize;
    return intervals;
}
```
