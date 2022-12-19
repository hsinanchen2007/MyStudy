>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 2)，其中n是prices数组的长度。空间复杂度是O(1)。

执行用时：804ms，击败5.01%。消耗内存：40MB，击败17.51%。

```java
public class Solution {
    public int maxProfit(int[] prices) {
        int result = 0;
        for (int i = 0; i < prices.length; i++) {
            for (int j = i + 1; j < prices.length; j++) {
                if (prices[j] - prices[i] > result) {
                    result = prices[j] - prices[i];
                }
            }
        }
        return result;
    }
}
```

# 解法二：录[0, x - 1]天的最小值

时间复杂度是O(n)，其中n是prices数组的长度。空间复杂度是O(1)。

执行用时：4ms，击败43.49%。消耗内存：38.3MB，击败51.91%。

```java
public class Solution {
    public int maxProfit(int[] prices) {
        int result = 0, n = prices.length;
        if (0 == n) {
            return result;
        }
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            result = Math.max(result, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return result;
    }
}
```