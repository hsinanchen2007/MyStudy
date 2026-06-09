### 解题思路
1. f[i]为前i天为止的最大收益
2. f[0]为0
3. 当prices[i]比prices[i-1]小，说明下跌了，f[i] = f[i-1]
4. 否则f[i] = prices[i] - curmin（历史低谷）

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize == 0) return 0;

    int *f=(int*)malloc(pricesSize*sizeof(int));
    (void)memset(f, 0, pricesSize*sizeof(int));

    int i;
    int curmin = prices[0];
    int max = 0;
    for (i=1; i<pricesSize; i++) {
        curmin = fmin(curmin, prices[i]);

        if (prices[i] < prices[i-1]) {
            f[i] = f[i-1];
        }
        else {
            max = fmax(max, prices[i] - curmin);
            f[i] = max;
        }
    }

    return max;
}
```