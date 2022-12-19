//每个光鲜的背后都有无数的汗水和不为人知的一面

//生意嘛，低买高卖；


局部最小值买入：今天比昨天跌了或者不涨不跌，并且明天一定上涨，那么今天买入；
```
prices[i]<=prices[i-1]&&prices[i]<prices[i+1]
```

局部最大值卖出：如果今天比昨天涨了并且明天一定跌或者不涨了，那么就把他卖出；
```
prices[i]>prices[i-1]&&prices[i]>=prices[i+1]
```
当然这里端点要特殊处理一下

//完整实现：
```
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n<2){
            return 0;
        }
        int ret = 0;
        //直接判断局部最大值卖出，局部最小值买入；
        boolean isBuyed = false;
        int buyPrices = -1;
        if(prices[0]<prices[1]){// 起始点判断
            isBuyed = true;
            buyPrices = prices[0];
        }
        
        for(int i = 1; i<n-1; i++){//  去除端点后的所有情况
           
            if(prices[i]>prices[i-1]&&prices[i]>=prices[i+1]){// 局部最大值
                if(isBuyed){
                   ret += (prices[i]-buyPrices);
                   isBuyed = false;
                }
            }
            if(prices[i]<=prices[i-1]&&prices[i]<prices[i+1]){// 局部最小值
                if(!isBuyed){
                    buyPrices = prices[i];
                    isBuyed = true;
                }
            }
            
        }
        
        if(prices[n-1]>prices[n-2]){// 结束点判断
            if(isBuyed){
                   ret += (prices[n-1]-buyPrices);
                }
        }
        return ret;
        
    }
    
```
