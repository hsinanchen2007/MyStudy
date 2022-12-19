### 解题思路
相当于在无序数组中找一个最小值和最大值的差，但是前提条件是最小值在最大值的左侧。因此我们每次找到一个新的最小值prices[i]的时候，都要将最大值更新为prices[i+1]，之前找到的最大差价仍保留。直到新的差价大于旧的差价，才会更新。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0||pricesSize==1)return 0;
    int buy=prices[0],sell=prices[1];
    int price=0;
    for(int i=1;i<pricesSize-1;i++){
        price=(sell-buy)>price?sell-buy:price;
        if(buy>prices[i]){
            buy=prices[i];
            sell=prices[i+1];
        }
        if(sell<prices[i+1])sell=prices[i+1];
    }
    price=(sell-buy)>price?sell-buy:price;
    return price;
}
```