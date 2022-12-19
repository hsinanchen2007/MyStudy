![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/680c70037e83703b942a2948a1e9a66dbd45edc33acdaddbd96f6f2b313cacf4-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length < 2){
            return 0;
        }
        int min = Math.min(prices[0], prices[1]);
        int res = prices[1] - prices[0];
        for(int i = 2; i<prices.length; i++){
            res = Math.max(res, prices[i] - min);
            min = Math.min(min, prices[i]);
        }      
        return res > 0 ? res : 0;
    }
}
```