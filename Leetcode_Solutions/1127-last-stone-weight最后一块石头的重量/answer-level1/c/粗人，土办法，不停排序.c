
执行用时 :4 ms, 在所有 c 提交中击败了73.31%的用户
内存消耗 :6.7 MB, 在所有 c 提交中击败了100.00%的用户


```

int CompareInt(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int lastStoneWeight(int* stones, int stonesSize)
{
    while(stonesSize > 2) {
        qsort(stones, stonesSize, sizeof(int), CompareInt);
        if (stones[stonesSize - 2] != stones[stonesSize - 1]) {
            stones[stonesSize - 2] = stones[stonesSize - 1] - stones[stonesSize - 2];
            stonesSize--;
        } else {
            stonesSize -= 2;
        }
    }
    if(stonesSize == 1) {
        return stones[0];
    } else if (stonesSize == 2){
        return abs(stones[0] - stones[1]);
    } else {
        return 0;
    }
}

```
