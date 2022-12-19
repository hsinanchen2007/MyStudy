![image.png](https://pic.leetcode-cn.com/ea3ea057f881a28bc733629420c338acd23ba710437466b9ab05dc5f862a5af8-image.png)

qsort排序，按照身高从大到小排序，身高一样按照人数从小到大排序，然后依次取出，对应人数即应该插入的位置；

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int CmpFunc(const void *a, const void *b)
{
    if ((*((int **)b))[0] == (*((int **)a))[0]) {
        return (*((int **)a))[1] - (*((int **)b))[1];
    }else {
        return (*((int **)b))[0] - (*((int **)a))[0];
    }
}
void Insert(int **rst, int*p, int pos, int size) {
    for (int i = size-1; i > pos; i--) {
        if (rst[i-1] != NULL) {
            rst[i] = rst[i-1];
        }
    }
    rst[pos] = p;
}
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = peopleSize;
    if (peopleSize == 0) return NULL;
    int **rst = (int **)calloc(peopleSize, sizeof(int*));
    int col = peopleColSize[0];
    *returnColumnSizes = (int*)calloc(peopleSize, sizeof(int));

    qsort(people, peopleSize, sizeof(int*), CmpFunc);
    //for (int i = 0; i < peopleSize; i++) {
    //    printf("[%d,%d]", people[i][0],people[i][1]);
    //}
    for (int i = 0; i < peopleSize; i++) {
        int pos = people[i][1];
        int* p = (int*)calloc(col, sizeof(int));
        memcpy(p, people[i], sizeof(int)*col);
        if (rst[pos] == NULL) {
            rst[pos] = p;
        }else {
            Insert(rst, p, pos, peopleSize);
        }
    }
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = col;
    }
    return rst;
}

```
