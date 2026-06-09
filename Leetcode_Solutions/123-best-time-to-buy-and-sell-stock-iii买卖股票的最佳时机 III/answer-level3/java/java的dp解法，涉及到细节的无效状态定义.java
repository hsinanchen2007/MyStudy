### 解题思路
其他一些题解写的比较冗余，这里我写个简单的题解。
本题使用dp来解决，dp的方案主要在于三点：
1. dp状态定义
2. dp方程：dp状态流转
3. dp状态初始化

#### dp状态定义
其实dp的状态就是一个各种可能性的组合，所以找到dp状态的定义，首先需要找出状态的所有影响参数。我们这么考虑，这个状态的值是最大理论，那么这个
理论被影响的参数是什么？
* 第几天买卖的价格
* 当前买卖的次数
* 当前是否持有股票
为什么是几个参数，需要自己去分析和体会。
那么我们dp状态定义就出来了：
```
/**
 * dp状态，3个参数分别是多少天，买卖了多少次（以买的次数作为计数），持有还是非持有（0不持有，1持有）
 */
float[][][] maxProfit = new float[priceLength][maxOpTimes + 1][2];
```
#### dp方程
每个状态的流转有两种情况：
* 未持有股票的状态是由 上个状态未持有不进行操作 或者 上个状态持有且卖出当前股票 两个状态流转过来 （两者取最大值）
```
 maxProfit[i][j][0] = Math.max(maxProfit[i - 1][j][0], maxProfit[i - 1][j][1] + prices[i]);
 ```
* 持有股票的状态是由 上个状态持有不进行操作 或者 上个状态未持有且这次买入股票 这两个状态流转过来（这两者取最大值）
```
 maxProfit[i][j][1] = Math.max(maxProfit[i - 1][j][1], maxProfit[i - 1][j - 1][0] - prices[i]);
 ```
 #### dp初始化
需要对初始dp状态进行定义，定义在第一天的所有可能性的值，只有两个状态是有效的，其他状态都是无效（无效记为负无穷）
这里有编码的细节需要注意，由于在不可能存在的状态，我们需要定义是一个负无穷，如果这里用Integer.MIN_VALUE来定义，在计算的时候
由于买入会进行-prices[i]，导致溢出，从而计算出错，这里使用float中的负无穷。
```
for (int count = 0; count <= maxOpTimes; count++) {
    maxProfit[0][count][0] = Float.NEGATIVE_INFINITY;
    maxProfit[0][count][1] = Float.NEGATIVE_INFINITY;
}

maxProfit[0][0][0] = 0;
maxProfit[0][1][1] = -prices[0];
```

#### dp状态压缩优化
如何使用滚动数组进行dp状态压缩和优化，参考https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/javagun-dong-shu-zu-jiang-di-kong-jian-zhan-yong-d/

## 执行结果
![image.png](https://pic.leetcode-cn.com/9590ee01f2247620678705de1d7944261ddd44520fab67ecc4a8f76f24864fe9-image.png)

### 代码

```java

/**
 * @author michael
 * @Description:
 * 针对股票买卖问题，使用dp重点是需要把dp方程和初始化状态设置好。
 * 定义dp状态，
 *
 *  dp状态，3个参数分别是多少天，买卖了多少次（以买的次数作为计数），持有还是非持有（0不持有，1持有）
 *  float[][][]maxProfit=new float[priceLength][maxOpTimes+1][2];
 *  每个状态的流转为：
 *  未持有股票的状态是由 上个状态未持有不进行操作 或者 上个状态持有且卖出当前股票 两个状态流转过来 （两者取最大值）
 *  maxProfit[i][j][0] = Math.max(maxProfit[i - 1][j][0], maxProfit[i - 1][j][1] + prices[i]);
 *  持有股票的状态是由 上个状态持有不进行操作 或者 上个状态未持有且这次买入股票 这两个状态流转过来（这两者取最大值）
 *  maxProfit[i][j][1] = Math.max(maxProfit[i - 1][j][1], maxProfit[i - 1][j - 1][0] - prices[i]);
 * @date 2020/2/5 1:48 PM
 */
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        int priceLength = prices.length;
        int maxOpTimes = 2;
        /**
         * dp装填，3个参数分别是多少天，买卖了多少次（以买的次数作为计数），持有还是非持有（0不持有，1持有）
         */
        float[][][] maxProfit = new float[priceLength][maxOpTimes + 1][2];

        /**
         * 需要对初始dp状态进行定义，定义在第一天的所有可能性的值，只有两个状态是有效的，其他状态都是无效（无效记为负无穷）
         * 这里有编码的细节需要注意，由于在不可能存在的状态，我们需要定义是一个负无穷，如果这里用Integer.MIN_VALUE来定义，在计算的时候
         * 由于买入会进行-prices[i]，导致溢出，从而计算出错，这里使用float中的负无穷。
         */
        for (int count = 0; count <= maxOpTimes; count++) {
            maxProfit[0][count][0] = Float.NEGATIVE_INFINITY;
            maxProfit[0][count][1] = Float.NEGATIVE_INFINITY;
        }

        maxProfit[0][0][0] = 0;
        maxProfit[0][1][1] = -prices[0];


        for (int i = 1; i < priceLength; i++) {
            for (int j = 1; j <= maxOpTimes; j++) {
                maxProfit[i][j][0] = Math.max(maxProfit[i - 1][j][0], maxProfit[i - 1][j][1] + prices[i]);
                maxProfit[i][j][1] = Math.max(maxProfit[i - 1][j][1], maxProfit[i - 1][j - 1][0] - prices[i]);
            }
        }

        float finalMaxProfit = 0;
        for (int j = 1; j <= maxOpTimes; j++) {
            if (maxProfit[priceLength - 1][j][0] > finalMaxProfit) {
                finalMaxProfit = maxProfit[priceLength - 1][j][0];
            }
        }

        return (int) finalMaxProfit;
    }
}
```