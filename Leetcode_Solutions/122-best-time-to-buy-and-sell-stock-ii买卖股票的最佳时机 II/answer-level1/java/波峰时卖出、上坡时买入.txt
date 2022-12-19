### 解题思路
正常逻辑：已买入股票时，在波峰处卖出；未买入股票时，在上坡时买入。（波峰、上坡都是把prices数组当做函数曲线看待）
![image.png](https://pic.leetcode-cn.com/36827d5a73f81b9c01d3912111d04d056c1c4fa1fb2fcbf4a4b904bbddae9b8e-image.png)


### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int flag = -1;
        int sum = 0;
        for (int i = 0; i < prices.length; i++) {
            if (flag == -1) {
                if (i != prices.length - 1 && prices[i] < prices[i + 1]) {
                    flag = prices[i];
                }
            } else {
                if (i == prices.length - 1 || prices[i] > prices[i + 1]) {
                    sum += prices[i] - flag;
                    flag = -1;
                }
            }
        }
        return sum;
    }
}
```