### 解题思路
此处撰写解题思路

### 代码

```c
int max1Profit(int* prices, int pricesSize) {
    if (pricesSize == 1)
        return 0;

    int max = 0;
    int *h = prices;
    int *t = prices + 1;
    int len = pricesSize - 1;

    for (int i = 0; i < len; i++) {
        if (*t -*h > max) 
            max = *t - *h;
        
        if (*t < *h)
            h = t;
        
        t++;
    }
    
    return max;
}

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 1)
        return 0;

    int max = max1Profit(prices, pricesSize);
    int max1 = 0;
    int max2 = 0;
    char *p = NULL;

    int len = pricesSize - 1;
    for (int i = 1; i < len; i++) {
        p = prices + i;
        max1 = max1Profit(prices, i) + max1Profit(p, pricesSize - i);
        //max2 = max1Profit(p, pricesSize - i);
        if (max < max1)
            max = max1;
    }

    return max;

}
```