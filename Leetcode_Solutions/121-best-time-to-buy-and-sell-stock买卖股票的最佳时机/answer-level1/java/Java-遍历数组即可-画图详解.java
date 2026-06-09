### 解题思路
该题有很多变式，买卖股票的方式花样很多，我们先来分析这道最基本的问题，即`最多只允许完成一笔交易`。当然，这`一笔交易`是说，只有执行一次买入操作，然后才能执行卖出操作。不能在卖出之前买入。这时题目的限定条件。

以`[7, 1, 5, 3, 6, 4]`为例，最好的情况下，我买入股票价格为`1`，然后卖出股票价格为`6`，这样我的利润才是最大的。（ps: 和瓜子二手车不同，我在这里赚的就是差价~）

但这类题目与现实中股票的买卖是不同的，现实生活中，我们不知道明天或者后天股票的卖出价格，这点需要注意。

**先说一下最基本的暴力吧**，假如当前我来到了索引为`i`的位置，我就需要遍历索引`i+1`及以后位置上的元素的元素，用后面的元素减去当前索引为`i`的元素，得到一个`差`。对于每一个位置`i`我都需要进行这个操作，然后更新这个`差`，取最大值，最后将`差`返回即可。

正如上面所说，`索引为 i 的元素`就是我当前买入的股票价格，得到的这个`差`就是当前`i`位置的利润，而题目要求就是返回最大的利润，我们就将其返回就好了。

### 代码 1
```java
public static int maxProfit1(int[] prices) {
        // 价格的数量不足两个以上，则不满足要求
        // 当然，当天买和当天卖的情况，没有必要
        if (prices == null || prices.length < 2) {
            return 0;
        }
        // 我就用 maxProfit 收集每次计算结果的最大利润
        // maxProfit 在遍历的过程中是不停的被更新的
        int maxProfit = 0;
        for (int i = 0; i < prices.length - 1; i++) {
            // 假如当前位置为 i，那么我就用从 i + 1 开始一直到末尾的每个数减去 i 位置上的数，
            // 从而找到最大的差值
            for (int j = i + 1; j < prices.length; j++) {
                int curProfit = prices[j] - prices[i];
                // 如果当前利润比最大利润还要大的话，
                // 我就把当前利润赋值给最大利润
                if (curProfit > maxProfit) {
                    maxProfit = curProfit;
                }
            }
        }
        return maxProfit;
    }
```

**再来看只需要遍历一遍数组的方式**，我首先用一个变量`minPrice`保存数组中最小的股票价格（当然这个参数是通过不停的遍历元素得到的），找到这个最小的股票价格以后，我就计算`当前的股票价格`与`最小的股票价格`的差，这个差就是`最大利润`。由于`当前的股票价格`在数组中是不停的在变化的，所以我们每次求出差之后，就需要对`最大利润`进行更新，等到遍历完数组之后，返回这个`最大利润`即可。

还是以`[7, 1, 5, 3, 6, 4]`为例，如下所示：
```
minPrice = Integer.MAX_VALUE
maxProfit = 0

价格：[ 7   1   5   3   6   4 ]
索引：  0   1   2   3   4   5
```
由于整数的最大值`Integer.MAX_VALUE`比这些数都要大，所以我维护一个最小价格`minPrice = Integer.MAX_VALUE`，用于记录数组中的最小值。一开始我来到了索引`0`位置，由于`0`位置上的数要比`minPrice`小，所以`minPrice`就被更新成了`7`。因为我还没有进行交易，所以最大利润`maxProfit`为`0`。

```
minPrice = 7
maxProfit = 0

价格：[ 7   1   5   3   6   4 ]
索引：  0   1   2   3   4   5
        ↑
```

接下来，我来到了索引为`1`的位置，由于元素`1`比最小值`7`还要小，则我们更新最小值，令`minPrice = 1`，最大利润不变。如下所示：

```
minPrice = 1
maxProfit = 0

价格：[ 7   1   5   3   6   4 ]
索引：  0   1   2   3   4   5
            ↑
```

接下来，来到了索引为`2`的元素`5`，由于`5`不小于`1`，所以不用更新最小值。但由于当前值`5`减去最小值`1`所产生的差是`4`，比最大利润`0`还大，所以我们此时更新这个`maxProfit = 5`。如下所示：
```
minPrice = 1
maxProfit = 5

价格：[ 7   1   5   3   6   4 ]
索引：  0   1   2   3   4   5
                ↑
```
后序的操作可以自己算一下，其最小值始终是`1`，而最大的利润会在元素`6`产生。


### 代码 2
```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;

        for (int i = 0; i < prices.length; i++) {
            // 如果当前的元素比之前的最小值还要小，
            // 那么就更新这个最小值
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 
            // 当前元素与最小值所产生的利润比之前的利润还要大的话，
            // 那么这正是我所需要的最大利润
            if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
}
```
### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)