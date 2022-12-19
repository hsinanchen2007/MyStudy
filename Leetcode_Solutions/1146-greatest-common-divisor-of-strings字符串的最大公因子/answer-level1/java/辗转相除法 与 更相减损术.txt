### 解题思路

题目要求 `X` 能除尽 `str1` 且 `X` 能除尽 `str2`，且 `X` 为最长。

那么可以理解为 `str1` 由 `m` 个 `X` 连接而成， `str2` 由 `n` 个 `X` 连接而成。由此可知 `str1 + str2` 由 `m + n` 个 `X` 拼接而成，而且 `str1 + str2` 与 `str2 + str1` 在值上是相等的。

然后此题就转化为了**求最大公约数**。`str1` 和 `str2` 长度的最大公约数，就是所求 `X` 的长度。

#### **方法一：辗转相除法**

> 辗转相除法， 又名欧几里得算法（Euclidean algorithm），目的是求出两个正整数的最大公约数。它是已知最古老的算法， 其可追溯至公元前300年前。

辗转相除法是递归算法，一句话概括这个算法就是：**两个整数的最大公约数，等于其中较小的数 和两数相除余数 的最大公约数**。
比如 10 和 25，25 除以 10 商 2 余 5，那么 10 和 25 的最大公约数，等同于 10 和 5 的最大公约数。

**代码实现：**

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // 如果 (str1 + str2) 和 (str2 + str1) 的值不相等
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        // 两个字符串长度的最大公约数
        int maxCommonDivisor = gcd(str1.length(), str2.length());
        return str1.substring(0, maxCommonDivisor);
    }
    
    // 辗转相除法求最大公约数
    private int gcd(int a, int b) {
        return (a % b == 0) ? b : gcd(b, a % b);
    }
}
```

#### **方法二：更相减损术**

> 更相减损术是出自《九章算术》的一种求最大公约数的算法，它原本是为约分而设计的，但它适用于任何需要求最大公约数的场合。
> 
> 原文：可半者半之，不可半者，副置分母、子之数，以少减多，更相减损，求其等也。以等数约之。

步骤：
1. 任意给定两个正整数，判断它们是否都是偶数。若是，则用 2 约简；若不是则执行第二步；
2. 以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止；
3. 则第一步中约掉的若干个 2 的积与第二步中等数的乘积就是所求的最大公约数。

通常编程实现更相减损术都比较粗略，直接就从第二步开始了，如下：

``` Java
// 更相减损术求最大公约数
public int gcd(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        return gcd(b - a, a);
    } else {
        return gcd(a - b, b);
    }
}
```

从第一步开始的：

``` Java
private int gcd(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        // 保证第一个数大，没啥原因，就是不想写那么多代码
        return gcd(b, a);
    } else {
        if ((a/2==0) && (b/2==0)) {
            // a，b都是偶数
            return gcd(a >> 1, b >> 1) << 1;
        } else if ((a/2==0) && (b/2!=0)) {
            // a是偶数，b是奇数
            return gcd(a >> 1, b);
        } else if ((a/2!=0) && (b/2==0)) {
            // a是奇数，b是偶数
            return gcd(a, b >> 1);
        } else {
            // a，b都是奇数
            return gcd(a - b, b);
        }
    }
}
```