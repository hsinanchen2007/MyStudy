### 解题思路
此处撰写解题思路
题意大概就是找到递增序列然后在递增序列的开始买入结束卖出
O（n）就可以找到
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int amount = 0;
        //找到递增序列开始买入结束卖出
        for(int i=0;i<prices.length;i++){
            int j=i;
            //选择递增序列的开始和结束位置，进行减法得到利润
            while(j+1 < prices.length && prices[j]< prices[j+1]){
                j++;
            } 
            if(i<j){
                amount+= prices[j]-prices[i]; 
                 i=j;
            }
        }
        return amount;
    }
}
```