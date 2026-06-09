```
class Solution {
    public int maxProfit(int[] prices) {
        ArrayList<Integer> profit_arr=new ArrayList<Integer>();
        for(int i=0;i<prices.length;i++){
            int in_price=prices[i];
            int out_price=prices[i];
            for(int j=i+1; j<prices.length;j++){
                if(out_price<prices[j]){
                    out_price=prices[j];
                }
            }
            int profit=out_price-in_price;
            profit_arr.add(profit);

        }
        
        if(profit_arr.size()==0){
            return 0;
        }else{
            int max_profit=profit_arr.get(0);
            for(int h=0;h<profit_arr.size();h++){
                if(profit_arr.get(h)>max_profit){
                max_profit=profit_arr.get(h);
                }
            }
            return max_profit;

        }

    }
}
```
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

首先创建一个储存profit有哪些可能性的数组，是用来最后遍历，选出最大值的。in_price是买入价，out_price是可能的卖出价，然后for循环遍历，找出最大值，相减得profit，放入数组中。最后循环遍历，找出最大值