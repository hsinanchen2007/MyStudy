### 解题思路
解题思路与 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/javade-dpjie-fa-she-ji-dao-xi-jie-de-wu-xiao-zhuan/
保持一致。
本文主要介绍如何降低dp状态的空间占用，使用上面提到的题解来计算的时候会提示超过内存使用空间，本篇题解主要介绍如何在dp的过程中使用滚动数组的
方式进行空间的压缩。

#### 滚动数组
dp中降维减少空间使用，一般都是使用滚动数组 https://www.cnblogs.com/PJQOOO/p/3900677.html的方案。
滚动数组说起来是一个新的词汇，实际上就是一个数组重用的意思。我们看下这个题目中的dp方程
```
maxProfit[i][j][0] = Math.max(maxProfit[i - 1][j][0], maxProfit[i - 1][j][1] + prices[i]);
maxProfit[i][j][1] = Math.max(maxProfit[i - 1][j][1], maxProfit[i - 1][j - 1][0] - prices[i]);
 ```
从dp方程可以看出在maxProfit这个数组中，maxProfit中的i只是和maxProfit中的i-1相关，考虑如果i=2，那么只需要有i=1即可，如果i=3，只需要有
i=2即可，以i取值范围为1,2,3为例，这种就是可以在往前递推的时候把这一维先存储i=1，用来计算i=2的数据，把i=2的数组覆盖到原来i=1的
数组上，然后用当前i=2的数据计算i=3，就是一个数组没有多行，使用一行循环使用，就是滚动数组的概念。
所以使用滚动数组的前提是后续的dp状态只和有限的前序状态有关（本题是1，就是前一个状态），并且状态之间需要有无后效性（就是当前状态的修改不会
影响之前的状态数据）。在本文的dp方程中，状态的转移就满足这个特性，所以可以使用滚动数组方案
如果没有使用滚动数组方案，上面的例子需要申请一个3行的数组，每一行存储结果。
如果一行数据为N，区别就是滚动数组方案申请的对象是int[N]，非滚动数组申请的对象是int[3][N]，可以节约2/3，上面的方案如果当前状态只跟前一个
状态相关，那么可以把空间减少为一行数据，大大节省空间。
滚动数组就是节约申请空间的作用。

以本地的空间占用为例，在一个case中，k是100000000，prices是10000的长度，如果用原来的三维数组来定义，一个int 4字节，那么需要的空间是
4 * 100000000 * 10000 * 2 / 1000/1000/1000 = 8000GB的空间。
使用滚动数组之后只需要4 * 10000 * 2 /1000 = 80K的空间。
空间节省非常明显

## 执行结果
![image.png](https://pic.leetcode-cn.com/9d5784ab0ffa79bc918f4fe05324ab57e931ef034ef8789799438507cc4fdaab-image.png)

### 代码

```java
/**
 * @author michael
 * @Description: 针对old算法的多维数组，由于空间占用比较大，导致无法通过，需要进行降维处理。
 * #### 滚动数组
 * dp中降维减少空间使用，一般都是使用滚动数组 https://www.cnblogs.com/PJQOOO/p/3900677.html的方案。
 * 滚动数组说起来是一个新的词汇，实际上就是一个数组重用的意思。我们看下这个题目中的dp方程
 * ```
 * maxProfit[i][j][0] = Math.max(maxProfit[i - 1][j][0], maxProfit[i - 1][j][1] + prices[i]);
 * maxProfit[i][j][1] = Math.max(maxProfit[i - 1][j][1], maxProfit[i - 1][j - 1][0] - prices[i]);
 *  ```
 * 从dp方程可以看出在maxProfit这个数组中，maxProfit中的i只是和maxProfit中的i-1相关，考虑如果i=2，那么只需要有i=1即可，如果i=3，只需要有
 * i=2即可，以i取值范围为1,2,3为例，这种就是可以在往前递推的时候把这一维先存储i=1，用来计算i=2的数据，把i=2的数组覆盖到原来i=1的
 * 数组上，然后用当前i=2的数据计算i=3，就是一个数组没有多行，使用一行循环使用，就是滚动数组的概念。
 * 所以使用滚动数组的前提是后续的dp状态只和有限的前序状态有关（本题是1，就是前一个状态），并且状态之间需要有无后效性（就是当前状态的修改不会
 * 影响之前的状态数据）。在本文的dp方程中，状态的转移就满足这个特性，所以可以使用滚动数组方案
 * 如果没有使用滚动数组方案，上面的例子需要申请一个3行的数组，每一行存储结果。
 * 如果一行数据为N，区别就是滚动数组方案申请的对象是int[N]，非滚动数组申请的对象是int[3][N]，可以节约2/3，上面的方案如果当前状态只跟前一个
 * 状态相关，那么可以把空间减少为一行数据，大大节省空间。
 * 滚动数组就是节约申请空间的作用。
 *
 * 以本地的空间占用为例，在一个case中，k是100000000，prices是10000的长度，如果用原来的三维数组来定义，一个int 4字节，那么需要的空间是
 * 4 * 100000000 * 10000 * 2 / 1000/1000/1000 = 8000GB的空间。
 * 使用滚动数组之后只需要4 * 10000 * 2 /1000 = 80K的空间。
 * 空间节省非常明显
 * @date 2020/2/5 5:11 PM
 */
@SuppressWarnings("Duplicates")
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        if (k == 0) {
            return 0;
        }
        int priceLength = prices.length;
        /**
         * 首先需要判断的一点是，一次交易至少需要 2 天，一天买，一天卖。因此如果 k 很大，大到大于等于 len / 2，就相当于股票系列的第 2 题，使用贪心算法去做就可以了。这是一个特判。
         * 与 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/  该题
         * 方法三解法一致
         */
        if (k > priceLength / 2) {
            return maxProfitWithNoLimit(prices);
        }
        /**
         * 当k > priceLength / 2的时候就会使用另外一种算法，这里的k大小就是<= priceLength，空间占用比较小
         */
        float[][] maxProfit = new float[k + 1][2];
        /**
         * 使用滚动数组之后，我们只有前一天的状态可以用，初始化的时候可以思考我们是从第二天开始计算，那么我们需要第一天的数据，第一天的数据
         * 就是如下的初始化。使用滚动数组最开始是不够清晰的，最开始不使用滚动数组方案进行编码，然后进行压缩优化成滚动数组方案。
         * 这个可以和leetcode123中非滚动数组的方案进行对比来理解滚动数组的意义。
         * 对数组进行初始化，这个相当于对于第一天的价格形成的maxProfit进行赋值
         */
        for (int count = 0; count <= k; count++) {
            maxProfit[count][0] = Float.NEGATIVE_INFINITY;
            maxProfit[count][1] = Float.NEGATIVE_INFINITY;
        }
        maxProfit[0][0] = 0;
        maxProfit[1][1] = -prices[0];

        for (int i = 1; i < priceLength; i++) {
            for (int j = 1; j <= k; j++) {
                /**
                 * 这里把原来的一维直接砍掉，每次进行数据的覆写，非滚动数组方案是每次生成新的一行数据
                 */
                maxProfit[j][0] = Math.max(maxProfit[j][0], maxProfit[j][1] + prices[i]);
                maxProfit[j][1] = Math.max(maxProfit[j][1], maxProfit[j - 1][0] - prices[i]);
            }
        }

        float finalMaxProfit = 0;
        for (int count = 0; count <= k; count++) {
            if (maxProfit[count][0] > finalMaxProfit) {
                finalMaxProfit = maxProfit[count][0];
            }
        }

        return (int) finalMaxProfit;
    }

    private int maxProfitWithNoLimit(int[] prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            if (prices[i + 1] > prices[i]) {
                maxProfit = maxProfit + (prices[i + 1] - prices[i]);
            }
        }
        return maxProfit;
    }
}
```