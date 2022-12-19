这个题要是真遇到，临时想一个解法出来还真不容易；个人觉得快排二维指针不好搞，最后只能搞了一个快排二维数组；
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int a[1110][2];
int cmp(const void *a, const void* b)
{
    if(*((int*)a) == *((int *)b))
    {
        return ((int*)a)[1] - ((int *)b)[1];
    }
    return *((int*)b) - *((int *)a);
}

void updatearray(int idx_a, int idx_b)
{
    int i;
    int p[2];
    p[0] = a[idx_b][0];
    p[1] = a[idx_b][1];
    for (i = idx_b; i > idx_a; i--)
    {
        a[i][0] = a[i - 1][0];
        a[i][1] = a[i - 1][1];
    }
    a[idx_a][0] = p[0];
    a[idx_a][1] = p[1];
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int ** returnarray = (int **) malloc(peopleSize * sizeof(people[0]));
    int i;

    for (i = 0; i< peopleSize;i++){
        returnarray[i] = (int *)malloc(*peopleColSize * sizeof(int));
        a[i][0] = people[i][0];
        a[i][1] = people[i][1];
    }
    qsort(a, peopleSize, sizeof(int*), cmp);
    for (i = 0; i< peopleSize; i++) {
    }
    for (i = 0; i< peopleSize; i++) {
        if (a[i][1] < i) {
            updatearray(a[i][1],i);
        }
    }
    for (i = 0; i< peopleSize; i++) {
        returnarray[i][0] = a[i][0];
        returnarray[i][1] = a[i][1];
    }
    
    *returnSize = peopleSize;
    
    for (i = 0; i< peopleSize; i++) {
        printf("%d, %d\n",returnarray[i][0], returnarray[i][1]);
    }
    returnColumnSizes[0] = peopleColSize;
    return returnarray;
}
```
