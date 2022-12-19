### 解题思路

暴力法

不用多说，两次循环 
第一层循环选择数组里第一个数，第二层循环选择数组里的第二个数，第二个数 - 第一个数
记录这个值，遍历完 则出现最大值


一次遍历

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;
        // 记录当前遍历的数组元素中最小的值
        int min = Integer.MAX_VALUE;
        for (int i=0; i < prices.length; i++) {
            if (prices[i] < min) min = prices[i];
            // 每次用当前值 与 最小值 做差 求最大利润
            max = Math.max(max, prices[i] - min);
        }
        return max;
    }
}
```