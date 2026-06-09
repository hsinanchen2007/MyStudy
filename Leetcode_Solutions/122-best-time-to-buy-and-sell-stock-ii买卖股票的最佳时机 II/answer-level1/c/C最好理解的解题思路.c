![image.png](https://pic.leetcode-cn.com/e3ad47a41b6e366b7b121b6c2c9845961b21da973a16832470222751e69a8f65-image.png)
思路：一个循环，贪心算法的核心就是不贪心：
只要后一天比我贵，我就买入，只要买入了后一天比我便宜我就卖，卖一笔就累加一下赚了多少钱；卖掉以后就具备再买入的条件了！
如果我还没有买入过，只要后一天比我便宜我就不买，一遍循环下来，最后如果我还买在手上没有卖的，最后卖掉就好。
代码：

int maxProfit(int* prices, int pricesSize){
    int i;
    int j;
    int buyPrices;
    int sellPrices;
    int sum=0;
    int havedByeFlag=0;
    if(pricesSize<=1){
        return 0;

    }
    for(i=0;i<pricesSize-1;i++){
        if(prices[i+1]>prices[i] && havedByeFlag==0){
            buyPrices = prices[i];
            havedByeFlag =1;

        } else if(prices[i+1]<=prices[i]){
            if(havedByeFlag){
               sellPrices=prices[i];
               sum+=(sellPrices - buyPrices); 
               havedByeFlag=0;

            }

        }

    }
    if(i == pricesSize-1 && havedByeFlag==1){
       sum+=(prices[i] - buyPrices);  
    }
    return sum;
}