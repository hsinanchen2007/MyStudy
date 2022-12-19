### 解题思路
参考官方题解，主要还是思路和技巧
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int Compare(const void *a, const void *b)
{
    int *i = *(int**)a;
    int *j = *(int**)b;

    return i[0] == j[0] ? (i[1] - j[1]) : (j[0] - i[0]);
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int **retPople = NULL;
    int curPos = 0;
    int numbers = 0;

    if (peopleSize == 0){
        *returnSize = 0;
        return NULL;
    }
    retPople = (int**)malloc(peopleSize * sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(peopleSize * sizeof(int));
    *returnSize = peopleSize;
    
    for(int i = 0; i < peopleSize; i++) {
        retPople[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
        memset(retPople[i],0,2*sizeof(int));
    }
    qsort(people, peopleSize, 2 * sizeof(int), Compare);
    if(people[0][1] > 0) {
        *returnSize = 0;
        return NULL;
    }
    for(int i = 0; i < peopleSize; i++) {
        //printf("check: %d,%d==========\n",people[i][0],people[i][1]);
        curPos = people[i][1];
        if (retPople[curPos][0] == 0) {
            retPople[curPos][0] = people[i][0];
            retPople[curPos][1] = people[i][1]; 
            numbers++;
            //printf("none: %d,%d\n",people[i][0],people[i][1]);
        } else {
            for (int j = numbers; j > people[i][1]; j--) {
                retPople[j][0] = retPople[j-1][0];
                retPople[j][1] = retPople[j-1][1];
                //printf("move: %d,%d\n",retPople[j-1][0],retPople[j-1][1]);
            }
            //printf("insert: %d,%d\n",people[i][0],people[i][1]);
            curPos = people[i][1];
            retPople[curPos][0] = people[i][0];
            retPople[curPos][1] = people[i][1];
            numbers++;
        }
    }
    
    return retPople;
}


```