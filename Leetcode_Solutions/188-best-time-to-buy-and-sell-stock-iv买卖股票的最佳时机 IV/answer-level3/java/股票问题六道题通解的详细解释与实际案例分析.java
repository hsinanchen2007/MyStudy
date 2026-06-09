## 买卖股票的最佳时机

这是一个系列的题目，核心的解体思路是使用动态规划找到最优解

- [121 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock)（简单）
- [122 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii)（简单）
- [123 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii)（困难）
- [188 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv)（困难）
- [309 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown)（中等）
- [714 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee)（中等）

对于每个问题，都有很多的文章解释了如何解决。但是，大多数解体思路都无法确定这些问题之间的联系，因此很难找到一种一致的方式来处理这一系列问题。这篇文章将介绍适用于所有这些问题的最通用的解决方案，并将其专门化为上述六个问题中的每一个。

### 通用情况

定义这个问题是解决这个问题的关键，通常人们在想到这类问题的时候都会觉得我最后的总利润取决于我买入和卖出的时机，只要我找到买入卖出的时机，这个问题就解决了。但是最后的结果是找到这些时间点特别难，从而无法得到最优的解，所以通过下面的分析重新定义一下问题。

首先介绍一下我们的变量：

- ``prices``：股票价格的数组
- ``n``：股票价格数组的长度
- ``i``：第``i``天，其中``i = 0, 1, 2...n-1``
- ``k``：允许的最大交易次数
- ``T[i][k]``：第``i``天进行最多``k``次交易之后得到的最大值

基础状态:

- ``T[-1][k] = 0`` （股票开始交易前是没有收益的）
- ``T[i][0] = 0``  （一次交易都没有进行，也是没有收益的）

现在的问题是如何用动态规划的思想把``T[n][k]``这个最优解分解成重叠的最优子问题进行解决。

最简单直接的方法是根据第``i``天的行为来判断第``i+1``天是什么样的状态。如果不考虑手里是否有股票，最多只能有三种操作：

- **买入**
- **卖出**
- **休息**

我们并不知道我们应该在第``i``天应该进行什么样的操作，只能是穷举也就是把所有能做的操作都做一遍，取其中最优的结果。为了知道第``i``天能够进行什么操作，我们引入另外一个状态，也就是手中持股的情况：

- ``0``代表我们手中没有股票，只能**买入**或者**休息**
- ``1``代表我们手中有一份股票，只能**卖出**或者**休息**

因为题目要求手中最多只能有一份股票，所以只需要这两个状态就可以了，如果手中可以持有多份股票，那么就需要的更多的数字来代表手中股票数量。如果允许做空股票，那么这个状态还有可能是负数。我们手中股票的数量是第``i``天操作的隐藏因素，也就影响了最大利润。

所以``T[i][k]``应该被分成两个部分：

- ``T[i][k][0]`` （在第``i``天进行最多``k``次交易之后并且经过当天的操作之后手里有``0``份股票的时候得到的最大值）
- ``T[i][k][1]`` （在第``i``天进行最多``k``次交易之后并且经过当天的操作之后手里有``1``份股票的时候得到的最大值）

接下来我们把公式重新写一遍

基本状态:

- ``T[-1][k][0] = 0`` （股票交易日之前收入为0）
- ``T[-1][k][1] = Integer.MIN_VALUE`` （股票开始交易之前是不可能是持有状态，这里标志为负无穷大）
- ``T[i][0][0] = 0`` （没有交易行为收入为0）
- ``T[i][0][1] = Integer.MIN_VALUE`` （如果不进行交易也是不可能持有股票的，标志为负无穷大，表示不可能）

状态转移关系：

- **``T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])``**
- **``T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])``**

对于第一个状态转移公式中的``T[i][k][0]``，只有两种情况能够达到这种状态，首先是第``i-1``天没有股票，今天我选择了**休息**，这个时候我的最大利润就是``T[i-1][k][0]``；如果第``i-1``天有股票，那么在今天必须以``prices[i]``的价格**卖出**，此时的收益是``T[i-1][k][1] + prices[i]``。而今天能够获得的最大收益就从这两种操作可能得到的结果中选出来，也就是选出这两个值中较大的一个。注意最大交易次数没有变，因为一次交易的完成必须由两个部分组成——**买入**和**卖出**，只有**买入**这个操作才能改变最大可以交易次数。

对于``T[i][k][1]``，也只有两种情况，首先是第``i-1``天没有股票，今天就必须**买入**，最大利润就必须从第``i-1``天的最大完成了``k-1``（**注意**这里不是``k``而是``k-1``，因为这个时候买入了一次，我们必须把交易次数也给累加一次，交易次数不能超过最多允许的次数）次交易操作扣除``prices[i]``，从而得到``T[i-1][k-1][0] - prices[i])``；如果第``i-1``天有股票，今天就只能**休息**，最大利润就是第``i-1``天的最大利润``T[i-1][k][1]``。

为了找到最后一天的最大收益，我们只需要遍历整个``prices``的数组，同时更新``T[i][k][0]``和``T[i][k][1]``，最后得到的可以输出的结果就是``T[i][k][0]``（我们最后必须要卖出手里的股票，完成最后一次交易，毕竟卖出肯定不卖出得到更多的收益）

### 实际案例分析

上面提到的6个股票问题可以根据``k``的值来分类

#### 121 买卖股票的最佳时机（k=1）

在这个案例中``k``是一个定值，原来的状态转移公式是：

``T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i])``
``T[i][1][1] = max(T[i-1][1][1], T[i-1][0][0] - prices[i]) = max(T[i-1][1][1], -prices[i])``

注意：根据我们的基本状态，``T[i][0][0] = 0``可以得到``T[i-1][0][0] = 0``

可以简化为:

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], -prices[i])``

通过上面的公式可以很容易的得到一个$O(n)$时间复杂度和$O(n)$空间复杂度的结果，但是注意到第``i``天的最大利润实际上只是取决于第``i-1``天的两个最大利润，所以空间复杂度可以所见到$O(1)$。下面是优化过的结果：

```java
public int maxProfit(int[] prices) {
    int T_i10 = 0, T_i11 = Integer.MIN_VALUE;

    for (int price : prices) {
        T_i10 = Math.max(T_i10, T_i11 + price);
        T_i11 = Math.max(T_i11, -price);
    }

    return T_i10;
}
```

用一个简单的表格来重现一下题目中的示例：

prices | 7 | 1 | 5 | 3 | 6 | 4
 :-:| :-: | :-: | :-: | :-: | :-: | :-:
T_i10 |0| 0| 4|4|5|**5**
T_i11 |-7|-1|-1|-1|-1|-1

``T_i10``这一行的最后一个数字**5**就是我们的最终结果。

如果我们仔细看一下上面的代码，就会发现``T_i11``是代表截止到当前列的所有的股票价格的负数的最大值，也就是所有股票价格中最小的值。至于``T_i10``，我们只需要决定哪个操作可以产生最大的收益，**卖出**或者**休息**。当我们在**卖出**的时候，股票的买入价格正好是``T_i11``，也就是第``i``天之前的最小价格。这也是我们在现实中为了最大化收益会做的事情，还有其他的解法，比如借鉴[最大子序列问题](http://sunshuyi.vip/2020/02/07/leetcode/leetcode-array/)而使用Kadane算法解决这个问题的方法：

```java
    public int maxProfit(int[] prices) {
        int maxCur = 0;    // 当前最大值
        int maxSoFar = 0;  // 全局最大值
        for(int i = 1; i < prices.length; i++) {
            maxCur = Math.max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = Math.max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
```

#### 122 买卖股票的最佳时机（k=正无穷大）

当``k``是正无穷大的时候，``k``和``k-1``其实就没有什么区别了。因为当交易无穷多次的时候，最大的利润不再受到交易次数的限制，所以``T[i-2][k-1][0] = T[i-2][k][0]``。所以我们就可以得到``T[i-1][k-1][0] = T[i-1][k][0]``和``T[i-1][k-1][1] = T[i-1][k][1]``。不过我们每天还是有两个未知的变量``T[i][k][0]``和``T[i][k][1]``，其中``k``是无穷大，所以状态转移方程变成了：

``T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])``
``T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i]) = max(T[i-1][k][1], T[i-1][k][0] - prices[i])``

这样的话我们又把``k``从方程中抹去了;

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i])``

同样的我们发现第``i``天的最大利润实际上只是取决于第``i-1``天的两个最大利润，也就可以用$O(n)$的时间复杂度和$O(1)$的空间复杂度的计算得到结果：

```java
public int maxProfit(int[] prices) {
    int T_ik0 = 0, T_ik1 = Integer.MIN_VALUE;
    for (int price : prices) {
        int T_ik0_old = T_ik0;
        T_ik0 = Math.max(T_ik0, T_ik1 + price);
        T_ik1 = Math.max(T_ik1, T_ik0_old - price);
    }
    return T_ik0;
}
```

注意到我们缓存了一下``T[i-1][0]``的值，因为这个值在第一个公式中被改变了，而第二个公式中需要用到它修改之前的值。用一个例子看一下：

prices | 3 | 2 | 6 | 5 | 0 | 3
 :-:| :-: | :-: | :-: | :-: | :-: | :-:
T_ik0 |0| 0| 4|4|4|**7**
T_ik1 |-3|-2|-2|-1|4|4

在这个例子中，``T_ik0``行最右边的值就是最大值**7**

不过稍加推断一下，就会发现其中的缓存是没有存在的必要的。根据这个情况下的状态转换方程，分两种情况：

1 **如果**``T[i-1][0] >= T[i-1][1] + prices[i]``

则``T[i][0] = T[i-1][0]``，代入到第二个状态方程中可以得到

``T[i][1] = max(T[i-1][1], T[i][0] - prices[i])``

2 **如果**``T[i-1][0] < T[i-1][1] + prices[i]``

则把右边的``prices[i]``移到不等号的左边，可以得到``T[i-1][1] > T[i-1][0] - prices[i]``

所以``T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i]) = T[i-1][1]``，最后的结果和``T[i][0]``或者``T[i-1][0]``是无关的，``T[i][0]``的值是新的还是旧的就无关紧要

所以根据以上两个假设，可以得到新的状态转移方程：

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], T[i][0] - prices[i])``

去掉缓存改进后的代码：

```java
public int maxProfit(int[] prices) {
    int T_ik0 = 0, T_ik1 = Integer.MIN_VALUE;
    for (int price : prices) {
        T_ik0 = Math.max(T_ik0, T_ik1 + price);
        T_ik1 = Math.max(T_ik1, T_ik0 - price);
    }
    return T_ik0;
}
```

还有另外一种算法，采用的**贪婪算法**：每次买股票都是在局部最低值然后再立刻在局部最高值卖掉。这就相当于找到``prices``序列中连续上升子序列，然后用序列的最大值减去最低值。这种方法其实相当于在只要能够盈利的时候交易就进行交易，尽可能多的获取收益。代码如下：

```java
    public int maxProfit(int[] prices) {
        int max = 0;
        for (int i = 0; i < prices.length-1; i++) {
            if (prices[i] < prices[i+1]) {
                max += prices[i+1] - prices[i];
            }
        }
        return max;
    }
```

prices | 3 | 2 | 6 | 5 | 0 | 3
 :-:| :-: | :-: | :-: | :-: | :-: | :-:
差值 |-1| 4|-1|-5|3|
max  |0 |4 |4 |4 |4|**7**

``max``这一行的最后一个值就是最后需要的最大值

#### 123 买卖股票的最佳时机III（k=2）

前两道题还是简单难度，理解起来可能比较简单。到了这里就瞬间变成了困难模式了。不过套用我们的公式，还是很容易解决的。

类似于``k=1``的案例，我们这次有四个变量：``T[i][1][0]``,``T[i][1][1]``,``T[i][2][0]``,``T[i][2][1]``，于是可以得到状态转移方程是：

``T[i][2][0] = max(T[i-1][2][0], T[i-1][2][1] + prices[i])``
``T[i][2][1] = max(T[i-1][2][1], T[i-1][1][0] - prices[i])``
``T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i])``
``T[i][1][1] = max(T[i-1][1][1], T[i][0][0] - prices[i]) = max(T[i-1][1][1], - prices[i])``

这里再次利用到了``T[i][0][0] = 0``这个初始条件。$O(n)$时间复杂度和$O(1)$空间复杂度的代码如下：

```java
public int maxProfit(int[] prices) {
    int T_i10 = 0, T_i11 = Integer.MIN_VALUE;
    int T_i20 = 0, T_i21 = Integer.MIN_VALUE;
    for (int price : prices) {
        T_i20 = Math.max(T_i20, T_i21 + price);
        T_i21 = Math.max(T_i21, T_i10 - price);
        T_i10 = Math.max(T_i10, T_i11 + price); //有没有感觉T_i10和T_i11的计算很眼熟？
        T_i11 = Math.max(T_i11, -price);        //和k=1的时候一模一样
    }
    return T_i20;
}
```

注意到这段代码中计算的排序，``T_i20``在最前面，紧接着``T_i21``，然后是``T_i10``，最后是``T_i11``，在空间复杂度为$O(1)$的代码中，这个顺序不能弄错了。在每次计算的时候使用的都是上次的旧值，一旦顺序调换如果不缓存上次的旧值，计算结果将会是错误的。通过将一个例子放到表格中来看下这个计算过程：

prices | 3 | 3 | 5 | 0 | 0 | 3 | 1 | 4
:-:| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-:
T_i20 | 0 | 0 | 2 | 2 | 2 | 5 |  5 | **6**
T_i21 | -3 | -3 | -3 | 2 | 2 | 2 | 2 | 2
T_i10 | 0 | 0 | 2 | 2 | 2 | 3 | 3 | 4
T_i11 | -3 | -3 | 0 | 0 | 0 | 0 | 0 | 0

在``T_i20``这一行最后一个值就是最终的结果，在算这个数字的过程中大家有没有发现一个很神奇的地方——最后两行也就是``T_i10``和``T_i11``跟上边没有任何的关系，完全就是``k=1``只能交易一次时候得到的结果。这道题：如果``k=1``，就直接把表格中``T_i10``这一行最后一个元素拿过去用就可以了；如果``k=2``，就用``T_i20``这一行的最后结果，如果``k=3``，我们就用``T_i30``这一行（如果有的话）最后的结果。这样就得到了第四层级的结果，如果是变数``k``，我们就直接用``T_ik0``，这个结果，这就是下面这道题的解法。

还有一个状态机的解法，在这里就不多讲了，感兴趣的同学看[这里](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/149383/Easy-DP-solution-using-state-machine-O(n))，以后会专门将到状态机这个算法的应用的。

#### 188 买卖股票的最佳时机IV（k为变量）

这个是最普遍的情况，每天我们都要更新这天结束的时候不同的``k``值并且手中有``0``份或者``1``份股票时候的最大利润。下面是简单版的代码：

```java
public int maxProfit(int k, int[] prices) {
        if (k <= 0 || prices == null || prices.length <= 1) {
            return 0;
        }

        int[] T_ik0 = new int[k]; // 手中没有股票的最大盈利数组
        int[] T_ik1 = new int[k]; // 手中有股票的最大盈利数组

        Arrays.fill(T_ik0, 0);              // 初始状态手中没有股票盈利是0
        Arrays.fill(T_ik1, Integer.MIN_VALUE);  // 初始状态不可能手中有股票，盈利是是不可能的，标志负无穷大

        for (int price : prices) {
            for (int i = k - 1; i >= 0; i--) {
                T_ik0[i] = Math.max(T_ik0[i], T_ik1[i] + price);
                T_ik1[i] = Math.max(T_ik1[i], (i==0?0:T_ik0[i-1]) - price); //在这一步要考虑到指针可能溢出的情况
            }
        }
        return T_ik0[k-1];
    }
```

在代码中的一个内嵌for循环中，我们用的是倒序遍历的方法，为了避免使用局部变量。

当我们在OJ中运行这段代码之后发现*内存溢出*了，没有通过测试。虽然时间复杂度是$O(kn)$，空间复杂度是$O(k)$，但是当``k``值过大的情况下，数组所占的内存空间会超出允许的空间范围，造成内存溢出，即使给了足够的内存，巨大的``k``值会给运行时间带来很大的消耗。

这个地方我们就做一个小小的改进，我们发现，如果当``k``超过了某个值之后，最大利润将不再取决于交易的次数，而取决于可以交易的股票的数量。所以接下来要做的就是找到这个关键的``k``值。

一次盈利的交易至少需要两天，一天买入，然后一天卖出，当然卖出价格要高于买入价格。如果数组``prices``的长度是``n``，那么最大可以交易的次数就是``n/2``。当``k``超过这个值的时候，就不可能再进行交易了，所以最大利润也不可能再进行增长。因此这个关键的``k``值就是``n/2``。如果出现``k>=n/2``的这样的情况，那么我们可以把``k``等同于正无穷大，这个时候问题的解决方法就可以等同于刚才的**第二个案例**，代码如下：

```java
    public int maxProfit(int k, int[] prices) {
        if (k <= 0 || prices == null || prices.length <= 1) {
            return 0;
        }

        if (k >= prices.length / 2) {    // 在这里如果交易频次可足够高，我们采用优化后的贪婪算法
            int max = 0;
            for (int i = 0; i < prices.length-1; i++) {
                if (prices[i] < prices[i+1]) {
                    max += prices[i+1] - prices[i];
                }
            }
            return max;
        }

        int[] T_ik0 = new int[k]; // 手中没有股票的最大盈利数组
        int[] T_ik1 = new int[k]; // 手中有股票的最大盈利数组

        Arrays.fill(T_ik0, 0);              // 初始状态手中没有股票盈利是0
        Arrays.fill(T_ik1, Integer.MIN_VALUE);  // 初始状态不可能手中有股票，盈利是是不可能的，标志负无穷大

        for (int price : prices) {
            for (int i = k - 1; i >= 0; i--) {
                T_ik0[i] = Math.max(T_ik0[i], T_ik1[i] + price);
                T_ik1[i] = Math.max(T_ik1[i], (i==0?0:T_ik0[i-1]) - price); //在这一步要考虑到指针可能溢出的情况
            }
        }
        return T_ik0[k-1];
    }
```

#### 309 最佳买卖股票时机含冷冻期（k=无穷大 交易有冷冻期）

这个情况和第二种情况也就是``k``是正无穷大很类似，只不过加了需要有交易冷却期的条件。原来的状态转移方程是：

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i])``

但是因为冷却期条件的存在，也就是说虽然可以交易无限次，但是在``i-1``天卖出股票后，不能在下一天也就是``i``天买入股票。换句话说就是要想在第``i``天买入股票，第``i-2``天结束的时候手里必须有``0``份股票，所以第二个公式中``T[i-1][0]``需要变成``T[i-2][0]``，状态转移方程变成了：

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], T[i-2][0] - prices[i])``

简化之后得到的$O(n)$时间复杂度和$O(1)$空间复杂度的答案是：

```java
    public int maxProfit(int[] prices) {
        /**
         * 这里T_ik0_pre缓存的是两天前手中没有股票时候最大收益
         * */
        int T_ik0_pre = 0, T_ik0 = 0, T_ik1 = Integer.MIN_VALUE;
        for (int price : prices) {
            int T_ik0_old = T_ik0;
            T_ik0 = Math.max(T_ik0, T_ik1 + price);
            T_ik1 = Math.max(T_ik1, T_ik0_pre - price);
            T_ik0_pre = T_ik0_old;  // 每一轮都要更新缓存中两天前的最大值
        }
        return T_ik0;
    }
```

用一个例子来复现一下动态规划的计算过程

prices | 3 | 3 | 5 | 0 | 0 | 3 | 1 | 4
:-:| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-:
T_i10 | 0 | 0 | 2 | 2 | 2 | 5 | 5 | **6**
T_i11 | -3 | -3 | -3 | 0 | 2 | 2 | 2 | 2

``T_i10``这一行最后的结果``6``就是最后的答案

#### 714 买卖股票的最佳时机含手续费（k=正无穷大但是有交易费）

这个情况和刚才的第二个案例也是非常相似的，只不过现在的我们的状态转移方程里面需要考虑到交易费。原来的状态转移方程是：

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i])``

现在我们需要在每次交易的时候都要付出交易费``fee``，所以最大利润是在第``i``天买入或者卖出股票之后，都要额外扣除一个``fee``，因此状态转移公式就变成了：

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])``
``T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i] -fee)``

或者

``T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i] - fee)``
``T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i])``

我们有两个地方可以选择扣除交易费，一个是在买入的时候，另一个是在卖出的时候。第一组状态转移公式对应的是在买入的时候缴纳手续费；第二组是在卖出的时候缴纳手续费。下面是两个情况下对应的代码：

**选择一**：买入时缴纳手续费

```java
    public int maxProfit(int[] prices, int fee) {
        int T_ik0 = 0, T_ik1 = Integer.MIN_VALUE;
        for (int price : prices) {
            int T_ik0_old = T_ik0;
            T_ik0 = Math.max(T_ik0, T_ik1 + price);
            T_ik1 = Math.max(T_ik1, T_ik0_old - price - fee);
        }
        return T_ik0;
    }
```

**选择二**：卖出时缴纳手续费

```java
public int maxProfit(int[] prices, int fee) {
    long T_ik0 = 0, T_ik1 = Integer.MIN_VALUE;   // 这里不再是int而是long
    for (int price : prices) {
        long T_ik0_old = T_ik0;
        T_ik0 = Math.max(T_ik0, T_ik1 + price - fee);
        T_ik1 = Math.max(T_ik1, T_ik0_old - price);
    }
    return (int)T_ik0;
}
```

这段代码中不再用``int``来表示定义的值而是``long``，因为到``price < fee``的时候，第一轮的计算可能``int``值溢出（``T_ik1 + price - fee < Integer.MIN_VALUE``）

注意在这两个范例代码中，``T_ik0_old``这个缓存也是可以不需要的，推论的方法同**案例二**

我们选择在买入时缴纳手续费，用一个例子来复线一下动态规划的计算过程：

prices | 1 | 3 | 2 | 8 | 4 | 9
:-:| :-: | :-: | :-: | :-: | :-: | :-:
T_i10 | 0 | 0 | 0 | 5 | 5 | **8**
T_i11 | -3 | -3 | -3 | -3 | -1 | -1

``T_i10``行的最后一个值``8``就是最后的结果

### 总结

在这个题目中，最普遍的情况是把问题定义成受第``i``天、最多``k``次交易以及手中持股情况三个变量影响的动态规划问题。**首先**最重要的是找出其中的状态转移方程，**然后**定义初始条件值，**接下来**根据不同的案例来定义各自的状态转移方程，**最后**精简或者优化代码以达到更好的时间和空间复杂度。

这个系列的题目是动态规划的一个典型的应用，希望在学习完这个题目之后，能够举一反三，看到其他的题目的时候也能这样有条有理的找到解决方案。

更多内容，请看我的[个人博客](http://sunshuyi.vip)

### 参考

> [一个通用方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)
> [Most consistent ways of dealing with the series of stock problems](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems)
> [详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--29/)
> [Kadane's Algorithm - Since no one has mentioned about this so far :)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/kadanes-algorithm-since-no-one-has-mentioned-about-this-so-far-in-case-if-interviewer-twists-the-input)
> [算法学习笔记（九）有限状态机 FSM 的应用](https://blog.csdn.net/thisinnocence/article/details/41171991)
> [Easy DP solution using state machine, O(n) time complexity, O(1) space complexity](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/149383/Easy-DP-solution-using-state-machine-O(n))
> [Share my thinking process](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/share-my-thinking-process)
