创建三个变量 maxNum最大值，minNum最小值，profit利润
当价格大于最大值时做三个操作，更新最大值，更新最小值，计算利润
当价格小于最小值时做两个操作，更新最小值，将最大值初始化
当出现新的最值之后，意味着将可能出现新的最大利润

```
  public int maxProfit(int[] prices) {
        if(prices.length<2){
            return 0;
        }
        int maxNum = -1;
        int minNum = -1;
        int profit = 0;
        for (int price : prices) {
            if(price>maxNum){
                if(minNum == -1 || minNum > price){
                    minNum = maxNum;
                }
                maxNum=price;
                int newProfit = maxNum-minNum;
                if(newProfit>profit){
                    profit = newProfit;
                }
            }else if(minNum == -1 || price < minNum){
                minNum = price;
                maxNum = -1;
            }
        }

        return profit;
    }
```
