### 解题思路
1. 除了牛逼还能说啥，加油理解吧

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int dp_i_1 = Integer.MIN_VALUE, dp_i_0 = 0, dp_pre = 0;
        for(int price : prices){
            int tmp = dp_i_0;
            dp_i_0 = Math.max(dp_i_0, dp_i_1 + price);
            dp_i_1 = Math.max(dp_i_1, dp_pre - price);
            dp_pre = tmp;
        }
        return dp_i_0;
    }
}
```