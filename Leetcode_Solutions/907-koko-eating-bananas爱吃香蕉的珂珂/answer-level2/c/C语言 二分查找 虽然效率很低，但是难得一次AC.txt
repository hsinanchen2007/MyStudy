### 解题思路
执行用时 :228 ms
, 在所有 C 提交中击败了5.83%的用户
内存消耗 :8.7 MB
, 在所有 C 提交中击败了13.76%的用户

### 代码

```c
int cmp(const void *a, const void *b) {
    int *m = (int *)a;
    int *n = (int *)b;

    return *m - *n;
}
int costTime(int *piles, int pilesSize, int K) {
    int tol = 0;
    for (int i = 0; i < pilesSize; i++) {
        int temp = piles[i] / K + (piles[i] % K > 0? 1: 0);
        tol += temp;
    }
    return tol;

}
int minEatingSpeed(int* piles, int pilesSize, int H){
    for (int i = 0; i < pilesSize; i++) {
        printf("piles[%d] = %d\n", i, piles[i]);
    }
    qsort(piles, (size_t)pilesSize, sizeof(int), cmp);
    for (int i = 0; i < pilesSize; i++) {
        printf("--piles[%d] = %d\n", i, piles[i]);
    }
    int left = 1; //这里记得left要从1 开始
    int right = piles[pilesSize - 1];
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int t = costTime(piles, pilesSize, mid);
        if (t < H) {
            right = mid - 1;
        } else if (t > H) {
            left = mid + 1;
        } else if (t == H) {
            right = mid - 1;
        }
    }
/*    if (left >= pilesSize) {  //不需要找不到的情况，只要左边界
        return -1;
    }*/
    return left;
}
```