### 解题思路
此处撰写解题思路
看了大佬的思路写的第二种解法，多想想，找一个最低点买进，一个最高点卖出
### 代码

```java


class Solution {
    public int maxProfit(int[] prices) {
        // int maxprofit=0;
        // for (int i = 0; i <prices.length-1 ; i++) {
        //     for (int j = i+1; j < prices.length; j++) {
        //         int profit=prices[j]-prices[i];
        //         if(profit>maxprofit){
        //             maxprofit=profit;
        //         }
        //     }
        // }
        // return maxprofit;
         int minprice= Integer.MAX_VALUE;
        int max=0;
        for (int i = 0; i <prices.length ; i++) {
            if(prices[i]<minprice){
                minprice=prices[i];
            }else if(prices[i]-minprice>max){
                max=prices[i]-minprice;
            }
        }
        return max;
    }
}

```