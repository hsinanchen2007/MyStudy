 在前一个价格比后一个小时，表示可以赚取利润，但是如果再后一个比当前价格高，则直接用后一个，直到后面的那个价格比前一个价格小          时，此时利润差最大
 eg :
 [5,3,3,4,6,8,7,5,6]
6 = (8-3) + (6-5)

[5,3,3,4,6,7,5,6,8]
 7 = (7-3)+(8-5)

[5,3,3,4,6,8,7,9,6]
 7= (8-3)+(9-7)


```
public static int maxProfit(int[] prices) {
    int profit = 0;//利润
    int preMin = -1;//上一个最小值
    int curMax = -1;//当前最大值
    for(int j = 1;j < prices.length;j++) {
        //如果当前索引处的元素大于上一个元素，则将当前元素赋值给当前最大值元素的变量
        if(prices[j-1] <= prices[j]){
            //给j 之前元素最小值赋值
            if(preMin == -1) {
                preMin = prices[j-1];
            }
            curMax = prices[j];
        } else {
            //此时，最大值元素减去前面最小值元素，得到最大的利润差
            profit = profit + (curMax - preMin);

            preMin = -1;//给上一个元素最小值还原-1
            curMax = -1;//给当前最大元素值归还原-1
        }
    }
    //当curMax 不为0时，表示当前curMax为最大元素，需要减去前面最小元素，得到利润
    if(curMax !=-1){
        profit = profit + (curMax - preMin);
    }
    return profit;
}
```


