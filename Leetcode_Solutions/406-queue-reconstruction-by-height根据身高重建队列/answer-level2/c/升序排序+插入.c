### 解题思路
先按照身高和体重升序排序，然后按照升序的顺序在结果列表中插入排序。
因为排好序之后，根据当前已经存在的结果确认当前人应该插入到什么位置。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int CheckParam(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    if (people == NULL || peopleSize <= 0 || peopleColSize == NULL ||
        returnSize == NULL || returnColumnSizes == NULL) {
        if (returnSize != NULL) {
            *returnSize = 0;
        }

        if (returnColumnSizes != NULL) {
            *returnColumnSizes = NULL;
        }

        return -1;
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    int *a1 = *(int **)a;
    int *b1 = *(int **)b;

    if (a1[0] == b1[0]) {
        return a1[1] - b1[1];
    }

    return a1[0] - b1[0];
}

int **ResultInit(int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    int **result = (int **)malloc(sizeof(int *) * peopleSize);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * peopleSize);
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        free(result);
        return NULL;
    }

    *returnSize = peopleSize;
    memset(result, 0, sizeof(int *) * peopleSize);

    return result;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    if (CheckParam(people, peopleSize, peopleColSize, returnSize, returnColumnSizes)) {
        return NULL;
    }

    int **result = ResultInit(peopleSize, peopleColSize, returnSize, returnColumnSizes);
    if (result == NULL) {
        return NULL;
    }

    qsort(people, peopleSize, sizeof(int *), cmp);
    for (int i = 0; i < peopleSize; ++i) {
        int j = people[i][1];

        // 选择策略，通过当前可以用的位置进行插入处理
        // 按照排好的队列进行插空处理。
        // 先跳过身高小于大于自身的j个，然后找到空处插入
        for (int k = 0; k < peopleSize; ++k) {
            if (j > 0) {
                if (result[k] == NULL || result[k][0] >= people[i][0]) { //当前没有占用的肯定比需要插入的更大，已经插入需要统计
                    j--;
                }
                continue;
            }

            if (result[k] == NULL) {
                result[k] = (int *)malloc(sizeof(int) * 2);
                memcpy(result[k], people[i], sizeof(int) * 2);
                break;
            }
        }
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
```