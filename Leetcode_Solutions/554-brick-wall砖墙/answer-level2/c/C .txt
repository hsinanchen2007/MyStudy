### 解题思路
求出每一行每块砖的前面转的和，然后排序，最后找出统一数字出现最多的次数。

### 代码

```c
#define MAX_NUM 20000

int gnum[MAX_NUM];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int leastBricks(int** wall, int wallSize, int* wallColSize)
{
    int wide = 0;
    int i, j;
    int perLineSum;
    int idx = 0;
    int maxLen = 0;

    if ((wall == NULL) || (wallColSize == NULL) || (wallSize == 0)) {
        return 0;
    }

    (void)memset(gnum, 0, sizeof(gnum));

    for (i = 0; i < wallSize; i++) {
        perLineSum = 0;
        for (j = 0; j < wallColSize[i]; j++) {
            perLineSum += wall[i][j];
            gnum[idx++] = perLineSum;
        }
        if (i == 0) {
            wide = perLineSum;
        }
    }

    qsort(gnum, idx, sizeof(int), cmp);

    for (i = 0; i < idx; ) {
        int tmp = gnum[i];
        int lenTmp = 1;
        if (gnum[i] == wide) {
            i++;
            break;
        }

        j = i + 1;
        while (j < idx) {
            if (gnum[j] == gnum[i]) {
                lenTmp++;
                j++;
            } else {
                i = j;
                if (lenTmp > maxLen) {
                    maxLen = lenTmp;
                }
                break;
            }
        }
    }

    return wallSize - maxLen;
}
```