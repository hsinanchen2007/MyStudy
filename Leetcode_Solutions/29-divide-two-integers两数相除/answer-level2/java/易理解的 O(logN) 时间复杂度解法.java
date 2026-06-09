### 解题思路

先考虑最简单的正整数除法的问题，再一步步优化题解。
正整数除法的实质就是反复进行减法，核心思想就是不断从 dividend 中减去 divisor，直到最后得到的结果再减为止，减法操作的数量就是结果。
但是，直接使用减法迭代暴力求解时时间复杂度是 O(N) 的，极易超时。

另外，知道了正整数除法的处理方法，还有符号不同的情况需要处理，另外也要注意可能出现的溢出情况。

#### 加速的核心思路

实际上，正整数除法的暴力解法每次只减去 1 个 divisor 太憨了，为什么不每次增加 divisor 的数量进行减法操作呢？这样，只要我们能够确定每次规律性的增加 divisor 的数量，就能加速求解过程，而且也能够按照增加的规律计算减去了多少个 divisor。

关键是确定增加的规律是什么，如果每次只增加 1 个 divisor，那算到最后也不过是 dividend 减去 $\frac{N(N - 1)}{2}$ 个 divisor，大体的复杂度是 O($\sqrt{N}$) 的，仍然不够理想。
那么，不如每次倍增上一次减法操作的减数，最后就是要减去 $\sum_{i=0}^N 2^{i}$ 个 divisor，结果时间复杂度就是 O($\log{N}$)。

然后，还要注意的是：每次减法操作都会比较剩余的 dividend 和递增后的减数的值，直到无法减去 1 个完整的减数。但是，此时减数极有可能远大于初始的 divisor，即剩余的 dividend 还能减去更多的 divisor。那么，就再把减数从 1 个 divisor 开始，对剩余的 dividend 进行递减操作即可，直到最后剩余的 dividend 小于 1 个 divisor。这样，我们统计所有减去的 divisor 数量就能得到答案。

而且，倍增操作可以由加法或者按位左移来实现，不违反题目的操作限制。

这样，正整数除法的优化解法核心思路已经完善，只需要进一步完善就可以解答本题了。

#### 正负号统一和溢出的处理

如果，dividend 和 divisor 符号不统一，那么我们只要提取出负号，就能把负数变为正数，而只要符号不统一结果就是负数，否则就是正数，所以符号不统一的问题容易解决。
但是，我们在把负数转为正数的时候发现：32 位整数负数和正数不是一一对应的，多一个 $-2^{31}$ 没有对应正数值。那么，何不逆转思路处理负整数除法，这样所有的正整数必定有负数对应。而实际上，因为负整数除法的思路和正整数基本一直，仍然是不断减去减数，只不过减数要不断递减，并且 dividend 大于减数的时候才不进行减法操作。

这样，在处理好了符号统一的同时，我们也轻易解决了结果溢出的问题。因为，只有计算 $-2^{31} \div -1$ 时会发生结果溢出问题，但是它不会超出负数除法的表示范围。
反而，我们应该注意减法迭代过程中的溢出问题。减数会在迭代过程中不断加倍，一旦减数大于 $-2^{16}$ 时，再倍增就会发生溢出问题，减数会由负数变为正数，之后减数倍增的结果就不如我们所想。所以，减法迭代必须判断减数值必须小于 0，一旦不满足条件就中止减法迭代，把减数重新设置位 1 个 divisor。

### 代码

最初版本的代码如下所示：

```java
class Solution {
    public int divide(int dividend, int divisor) {
        boolean isNegative = (dividend > 0) ^ (divisor > 0);
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        int total = 0;
        while (dividend <= divisor) {
            int tmpDivisor = divisor;
            int cnt = -1;
            while (tmpDivisor >= dividend && tmpDivisor < 0) {
                dividend -= tmpDivisor;
                tmpDivisor <<= 1;
                total += cnt;
                cnt <<= 1;
            }
        }
        if (isNegative) return total;
        return total == Integer.MIN_VALUE ? Integer.MAX_VALUE : -total;
    }
}
```

**注意：**
1. 布尔值的异或操作可以省略繁琐的布尔表达式嵌套，当然也可以用 `(dividend ^ divisor) < 0` 替代。
2. 次代码便于理解，还可以额外对几个特殊情况进行剪枝处理，缩短运行时间（非必要）

增加剪枝代码后的结果如下：

```java
class Solution {
    public int divide(int dividend, int divisor) {
        // 剪枝处理
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == Integer.MIN_VALUE ? Integer.MAX_VALUE : -dividend;

        boolean isNegative = (dividend > 0) ^ (divisor > 0);
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        int total = 0;
        while (dividend <= divisor) {
            int tmpDivisor = divisor;
            int cnt = -1;
            while (tmpDivisor >= dividend && tmpDivisor < 0) {
                dividend -= tmpDivisor;
                tmpDivisor <<= 1;
                total += cnt;
                cnt <<= 1;
            }
        }

        return isNegative ? total : -total;
    }
}
```

提交结果如下：
![Snipaste_2020-03-17_19-26-16.png](https://pic.leetcode-cn.com/3f7d7af426417455b2914761405c0dedf0cb6fbc1b4e98759c2c6a4a4400f465-Snipaste_2020-03-17_19-26-16.png)

