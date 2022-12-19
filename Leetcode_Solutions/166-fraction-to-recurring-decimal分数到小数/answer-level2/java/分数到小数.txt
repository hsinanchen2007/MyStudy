## 概要

这是一道非常显然的代码题，但需要考虑很多细节。

## 注意

1. 不需要复杂数学，只需要数学的基本知识。了解长除法的运算规则。

2. 使用长除法计算 $\dfrac{4}{9}$，循环节很显然就会找到。那么计算 $\dfrac{4}{333}$ 呢，能找到规律吗？

3. 注意边界情况！列出所有你可以想到的测试数据并验证你的代码。

## 题解

#### 方法 1：长除法

**想法**

核心思想是当余数出现循环的时候，对应的商也会循环。

$$
\begin{array}{rll}
 0.16 \\
6 {\overline{\smash{\big)}\,1.00}} \\[-1pt]
\underline{0\phantom{.00}} \\[-1pt]
1\phantom{.}0 \phantom{0} && ...\ 余数为\ 1，标记\ 1\ 出现在位置\ 0。\\[-1pt]
\underline{\phantom{0}6\phantom{0}} \\[-1pt]
\phantom{0}40 && ...\ 余数为\ 4，标记\ 4\ 出现在位置\ 1。\\[-1pt]
\underline{\phantom{0}36} \\[-1pt]
\phantom{00}4 && ...\ 余数为\ 4，在位置\ 1\ 出现过，所以循环节从位置\ 1\ 开始，为\ 1(6)。\\[-1pt]
\end{array}
$$

**算法**

需要用一个哈希表记录余数出现在小数部分的位置，当你发现已经出现的余数，就可以将重复出现的小数部分用括号括起来。

再出发过程中余数可能为 0，意味着不会出现循环小数，立刻停止程序。

就像[两数相除](https://leetcode-cn.com/problems/divide-two-integers/?utm_source=LCUS&utm_medium=banner_redirect&utm_campaign=transfer2china)问题一样，主义考虑负分数以及极端情况，比如说 $\dfrac{-2147483648}{-1}$。

下面列出了一些很好的测试样例：

| 测试样例                                 | 解释                                       |
| ------------------------------------ | ---------------------------------------- |
| $\frac{0}{1}$                      | 被除数为 0。                                  |
| $\frac{1}{0}$                      | 除数为 0，应当抛出异常，这里为了简单起见不考虑。                |
| $\frac{20}{4}$                     | 答案是整数，不包括小数部分。                           |
| $\frac{1}{2}$                      | 答案是 0.5，是有限小数。     |
| $\frac{-1}{4}$ 或 $\frac{1}{-4}$ | 除数被除数有一个为负数，结果为负数。 |
| $\frac{-1}{-4}$                    | 除数和被除数都是负数，结果为正数。 |
| $\frac{-2147483648}{-1}$           | 转成整数时注意可能溢出。 |

```java []
public String fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
        return "0";
    }
    StringBuilder fraction = new StringBuilder();
    // If either one is negative (not both)
    if (numerator < 0 ^ denominator < 0) {
        fraction.append("-");
    }
    // Convert to Long or else abs(-2147483648) overflows
    long dividend = Math.abs(Long.valueOf(numerator));
    long divisor = Math.abs(Long.valueOf(denominator));
    fraction.append(String.valueOf(dividend / divisor));
    long remainder = dividend % divisor;
    if (remainder == 0) {
        return fraction.toString();
    }
    fraction.append(".");
    Map<Long, Integer> map = new HashMap<>();
    while (remainder != 0) {
        if (map.containsKey(remainder)) {
            fraction.insert(map.get(remainder), "(");
            fraction.append(")");
            break;
        }
        map.put(remainder, fraction.length());
        remainder *= 10;
        fraction.append(String.valueOf(remainder / divisor));
        remainder %= divisor;
    }
    return fraction.toString();
}
```