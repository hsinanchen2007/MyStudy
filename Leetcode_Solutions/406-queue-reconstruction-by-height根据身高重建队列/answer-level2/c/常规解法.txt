### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp(const void *a, const void *b)
{
    const int *people1 = *(const int **)a;
    const int *people2 = *(const int **)b;

    if (people1[1] == people2[1]) {
        // 系数相同，按身高升序排列
        return people1[0] - people2[0];
    } else {
        // 按系数升排列
        return people1[1] - people2[1];
    }
}

int **reconstructQueue(int **people, int peopleSize, int *peopleColSize, int *returnSize, int **returnColumnSizes)
{
    int sum = 0;
    int i, k;
    int *tmp;
    int **ret = (int **)malloc(peopleSize * sizeof(int *));

    for (int n = 0; n < peopleSize; n++) {
        ret[n] = (int *)malloc(*peopleColSize * 4);
        ret[n][0] = people[n][0];
        ret[n][1] = people[n][1];
    }

    qsort(ret, peopleSize, sizeof(int *), comp);
 
    for (i = 0; i < peopleSize; i++) {
        tmp = ret[i];
        if (tmp[1] != 0) {
            break;
        }
    }

    int r = peopleSize - i;
    for (int j = 0; j < r; j++) {
        sum = 0;
        k = 0;

        for (k = 0; k < i; k++) {
            if (tmp[0] <= ret[k][0]) {
                sum++;
            }
            if (sum > tmp[1]) {
                break;
            }
        }

        if (k < i) {
            for (int m = 0; m < i - k; m++) {
                ret[i - m] = ret[i - m - 1];
            }
            ret[k] = tmp;
        }

        if (i < peopleSize - 1) {
            i++;
            tmp = ret[i];
        } else {
            break;
        }
    }
    *returnSize = peopleSize;
    *returnColumnSizes = peopleColSize;

    return ret;
}
```