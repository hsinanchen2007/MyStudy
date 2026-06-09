### 解题思路
此处撰写解题思路
若a<=b<=c<=d,则最大收益为d-a=(d-c)+(c-b)+(b-a),所以，只要找到一个比他前一个数大的数，就可以将他们的差值加入到收益里面，而且累积起来就是最大收益。
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        for(int i=1;i<prices.length;i++){
            if(prices[i]>prices[i-1]) profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
}
```