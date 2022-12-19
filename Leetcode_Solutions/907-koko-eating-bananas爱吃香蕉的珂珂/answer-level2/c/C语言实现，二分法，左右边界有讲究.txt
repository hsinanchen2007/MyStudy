### 解题思路
此处撰写解题思路

### 代码

```c
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int minEatingSpeed(int* piles, int pilesSize, int H){
    //if (pilesSize == 1) {
    //    return (piles[0] + H - 1) / H;
    //}
    qsort(piles, pilesSize, sizeof(int), cmp);
    int left = 1; //piles[0] / H;
    int right = piles[pilesSize-1];
    int mid;
    int time=0;
    while (left < right) {
        mid = (left + right) / 2;
        time = 0;
        //printf("%d %d %d\n", mid, left, right);
        for (int i=0; i<pilesSize; i++) {
            time += (piles[i] + (mid - 1)) / mid;
        }
        //printf("time=%d\n", time);
        if (time > H)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
```