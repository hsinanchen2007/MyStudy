int maxProfit(int* prices, int pricesSize){
    
    int i;
    int minPrice;
    int minIndex;    
    int end;
    int maxProfit;
    int tmpProfit;
    int saleDay;

    /* 合法性校验 */
    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    }

    /* 找最小值的索引 */
    minPrice = prices[0];
    minIndex = 0;
    for (i  = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
            minIndex = i;
        }
    }

    printf("%u, %u", minPrice, minIndex);

    /* 最小值的索引是数组的最后一个元素的索引 */
    if (minIndex == pricesSize - 1) {
        return 0;
    }

    /* 滑动窗口的算法 */
    maxProfit = 0;
    for (end = minIndex + 1; end < pricesSize; end++) {
        tmpProfit = prices[end] - prices[minIndex];
        if (tmpProfit > maxProfit) {
            maxProfit = tmpProfit;
            saleDay = end + 1;
        }
    }

    return saleDay;
}