### 解题思路
到达每一个股票价格时，都可能存在多种状态
每一次买或卖都是一个状态（第一次买--1买，1卖，2买，2卖。。。）
每一种买或卖状态都只有两种方式到达：
1. 上一个价格的此状态
2. 上一个价格的前一状态（如2卖的前一状态是2买，2买的是1卖）加上此处股票价格（本次状态是卖）或减去此处股票价格（本次状态是买）

我们记录每个状态的，两种到达方式的最大值，作为状态的值

### 代码

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices.length==0||k==0) return 0;
        if(k>prices.length/2) return maxProfit(prices);//k比长度一半大，相当于可以进行任意次交易，获得每段上升相加
        int[][] profit = new int[prices.length][2*k];//2k个状态，1买1卖2买2卖...
        int result = 0;

///////////////////////////////////////////////////////////////////////////
//第一个股票价格时的赋值
        profit[0][0] = 0-prices[0];//把第一次的买赋值
        for(int i=2;i<2*k;i+=2){//把后面还没到的买赋值一个很小的数
            profit[0][i] = (int)Math.pow(-2,31);
        }
///////////////////////////////////////////////////////////////////////////
//从第二个股票价格开始按状态转移方程
        for(int i=1;i<prices.length;i++){
            profit[i][0] = Math.max(profit[i-1][0],0-prices[i]);
            for(int j=1;j<2*k;j++){
                if((j&1)==1){
                    profit[i][j] = Math.max(profit[i-1][j],prices[i]+profit[i-1][j-1]);
                }else{
                    profit[i][j] = Math.max(profit[i-1][j],profit[i-1][j-1]-prices[i]);
                }
            }
        }
////////////////////////////////////////////////////////////////////////////
//选择所有卖状态中最大值
        for(int i=1;i<2*k;i+=2){
            result = Math.max(result,profit[prices.length-1][i]);
        }

        return result;
    }

    public int maxProfit(int[] prices) {
        if(prices.length==0) return 0;
        int result = 0;
        int minIndex = 0;

        for(int i=1;i<prices.length;i++){
            if(prices[i]>=prices[i-1]){
                continue;
            }
            else{
                result+=prices[i-1]-prices[minIndex];
                minIndex = i;
            }

        }
        result+=prices[prices.length-1]-prices[minIndex];

        return result;

    }

}
```