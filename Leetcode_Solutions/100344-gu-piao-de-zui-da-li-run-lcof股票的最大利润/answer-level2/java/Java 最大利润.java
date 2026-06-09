### 解题思路
默认未开始计算时，最大利润为0
当数组元素小于等于1时，无需考虑利润一定为0
当数组元素大于1时，则需要初始化max为0，min设置第一个元素
后续处理过程中，每次首先确认当前元素是否是一个更小元素，是则更新min
然后将当前max和当前元素减去min的差值进行比较，较大值设置为max即可
最后返回max的value即可

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }

        int max = 0;
        int min = prices[0];
        for (int price : prices) {
            if (price < min) {
                min = price;
            }
            if (max < price - min) {
                max = price - min;
            }
        }

        return max;
    }
}
```