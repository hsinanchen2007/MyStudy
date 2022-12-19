```c
int* sequentialDigits(int low, int high, int* returnSize){
    int idx = 0, idy = 0;
    int pop_low = low;
    int *list = (int*)malloc(sizeof(int)*45);

    for (;pop_low >= 10; idx++) {
        pop_low /= 10;
    }

    int val = 0;
    while(val < high) {
        if (pop_low + idx >= 10) {
            pop_low = 1;
            ++idx;
        }
        val = helper(pop_low++, idx);
        if (val >= low && val <= high) {
            *(list+idy++) = val;
        }
    }
    int *retList = (int *)malloc(sizeof(int)*idy);
    memcpy(retList, list, sizeof(int)*idy);
    free(list);
    *returnSize = idy;
    return retList;
}

int helper(int pop_low, int digit) {
    int ret = 0;
    for (int idx=0; idx <= digit; idx++) {
        ret = ret*10 + pop_low;
        pop_low += 1;
    }
    return ret;
}
```
