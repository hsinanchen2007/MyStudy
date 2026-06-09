### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int res=0;
        for(int i=0;i<prices.length-1;i++){
            for(int j=i+1;j<prices.length;j++){
                if(prices[j]>prices[i]){
                    res=Math.max(res,prices[j]-prices[i]);
                }
            }
        }
        return res;
    }
}
```