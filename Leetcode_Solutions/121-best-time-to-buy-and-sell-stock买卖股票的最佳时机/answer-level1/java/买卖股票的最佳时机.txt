### 解题思路
暴力破解
由于卖股票只能在买之后进行操作，所以第二层循环从i+1开始

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        for(int i=0;i<prices.length-1;i++){          
            for(int j=i+1;j<prices.length;j++){
                if(prices[j] - prices[i] > max){
                    max = prices[j] - prices[i];
                }
            }
        }

        return max;

    }
}
```