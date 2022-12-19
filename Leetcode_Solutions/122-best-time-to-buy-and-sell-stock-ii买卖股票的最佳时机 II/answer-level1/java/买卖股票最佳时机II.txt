# 一次循环就够了 
  这个题只要注意间隔买卖操作就可以了(先买再卖)，所以只需要找到每一次买入的最小值，和卖出的最大值，然后判断是买入还是卖出就可以了，最后将所有买卖的收益加起来就是最大受收益了。
例如[4,3,1,2,5,6,2,2,4,5]
第一轮：
   最小买入为:1
   最大卖出为:6
第二轮：
   最小买入为:2
   最大卖出为:5
最后输出:8
下面是我的代码：
```
class Solution {
    public int maxProfit(int[] prices) {
        //isSell 是买入还是卖出的标志，最开始为 false,即最开始为买入阶段
        boolean isSell=false;
        //profit为收益，buyPrice为买入价格
        int profit=0,buyPrice=0;
        for(int i=0;i<prices.length-1;i++){
            //prices[i]<prices[i+1]&&!isSell这个是找到当前一轮买入的最低价格
            if(prices[i]<prices[i+1]&&!isSell){
                buyPrice=prices[i];
                isSell=true;//买入后，是卖出阶段，所以变为true
            }
            // //prices[i]<prices[i+1]&&!isSell这个是找到当前一轮卖出的最高价格
            if(prices[i]>prices[i+1]&&isSell){
                profit+=prices[i]-buyPrice;//计算收益
                isSell=false;//卖完后是买入，变为false
            }
            //当买入后，prices数组里找不到prices[i]>prices[i+1]，（即买入后，后面的价格升序）
            if(i==prices.length-2&&isSell){
                //用prices[length-1]作为卖出价去计算收益
                profit+=prices[i+1]-buyPrice;
            }
        }
        return profit;
    }
}
  
```
