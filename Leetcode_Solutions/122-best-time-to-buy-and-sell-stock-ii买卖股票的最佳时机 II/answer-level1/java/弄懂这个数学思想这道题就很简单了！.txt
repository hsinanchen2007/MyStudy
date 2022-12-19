### 解题思路
1.
![image.png](https://pic.leetcode-cn.com/18c0f5bded0728e64d6733f28c8a547efae5f0ba74b471eab13dca07b9bd0834-image.png)
2.代码参照leetcode官方解答，只是觉得它讲的没有自己理解的透彻。
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int i = 0;
       if(prices.length==0)return 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        //这里面用到的一个就是若出现两个峰谷，则无论什么形式它的总利润都是小于两次分别峰-谷相加
        while (i < prices.length - 1) {
                //这里是为了找到低谷
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
                //这里是为了找到高峰，若是有相连的峰则取后面比较高的峰
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
                //得到一次利润，然后再去while循环看是否还有峰-谷
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
}
```
