```
typedef struct {
    int index;
    int group_nums;
}group;

int Cmp(const void * a, const void * b) 
{
    group * c = (group*)a;
    group * d = (group*)b;
    if (c->group_nums > d->group_nums) {
        return 1;
    } else {
        return -1;
    }
}

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes)
{
    int index_r = 0;
    group Group[groupSizesSize]; 
    *returnSize = 0;

    for (int i = 0; i < groupSizesSize; i++) {
        Group[i].index = i;
        Group[i].group_nums = groupSizes[i];
    }        

    qsort(Group, groupSizesSize, sizeof(group), Cmp);
    int ** ret = (int **)malloc(groupSizesSize * sizeof(int*));

    for (int i = 0; i < groupSizesSize;) {
        int step = Group[i].group_nums;
        ret[index_r] = (int*)malloc(step * sizeof(int));
        returnColumnSizes[0][index_r] = step;
        for (int j = 0; j < step; j++) {
            ret[index_r][j] = Group[i++].index;
        }
        index_r++;
    }

    *returnSize = index_r;
    return ret;
}
```
