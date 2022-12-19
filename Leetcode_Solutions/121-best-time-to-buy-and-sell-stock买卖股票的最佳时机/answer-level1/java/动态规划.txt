### 解题思路
前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;  //共n天
        if(n==0){
            return 0;
        }
        int f[]=new int[n];
        int minPrice=Integer.MAX_VALUE;
        f[0]=0; //第一天买入然后卖出收益为0
        for(int i=1;i<n;i++){  
            if(prices[i-1]<minPrice){
                minPrice=prices[i-1];  //前i-1天中的最小价格
            }
            f[i]=Math.max(f[i-1],prices[i]-minPrice);
        }
        if(f[n-1]>0){
            return f[n-1];
        }
        else return 0;    
    }
}
```