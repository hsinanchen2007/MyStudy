### 解题思路
此处撰写解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
98.80%
的用户
内存消耗 :
39.5 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE, maxprofit = 0;
        for (int i = 0; i < prices.length ; i++){
            if (prices[i] < min) min = prices[i];
            if (prices[i] - min > maxprofit) maxprofit = prices[i] - min;
        }
        return maxprofit;
    }
}
```