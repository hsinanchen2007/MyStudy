

![image.png](https://pic.leetcode-cn.com/179b87843673a56ed884ada929bff25b7fc48220fc683040f4b41240f2b791da-image.png)


```
int maxProfit(int* prices, int pricesSize){
    int inPrice = 0;
    int i = 0;
    int maxPrice = 0;

    if (pricesSize == 0 || prices == NULL) {
        return 0;
    }

    inPrice = prices[0];
    for (i = 1; i < pricesSize; i++) {
        if (prices[i] > inPrice) {
            if (prices[i] - inPrice > maxPrice) {
                maxPrice = prices[i] - inPrice;
            }
            continue;
        }

        if (prices[i] < inPrice) {
            inPrice = prices[i];
        }
    }

    return maxPrice;
}
```