### 解题思路
先对数组第一列元素有小到大排序，然后动态规划计算以第i行结尾的话最多有多少个数对（dp[i]）

### 代码

```c
int cmp(const void *a,const void *b)
{
    int *ap = *(int **)a;       
    int *bp = *(int **)b;

    if(ap[0] == bp[0])
        return ap[1] - bp[1];
    else
        return ap[0] - bp[0];
} 

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize){
    int* dp = (int*)malloc(sizeof(int) * pairsSize);
    int i, j;
    int max = 0;

    qsort(pairs, pairsSize, sizeof(pairs[0]), cmp);

    for(i = 0; i < pairsSize; i++) {
        dp[i] = 1;
    }

    for(i = 0; i < pairsSize; i++) {
        for(j = 0; j < i; j++) {
            if(pairs[i][0] > pairs[j][1]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }

    for(i = 0; i < pairsSize; i++) {
        max = fmax(max, dp[i]);
    }
    return max;
}
```