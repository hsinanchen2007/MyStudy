### 解题思路
这还要啥思路
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        int max=0;
        for(int i=prices.length-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                profit=prices[i]-prices[j];
                if(profit>max){
                    max=profit;
                }
            }
        }
        return max;
    }
}
```