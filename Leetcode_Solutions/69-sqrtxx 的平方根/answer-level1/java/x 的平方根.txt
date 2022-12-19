#### 整数平方根

存在整数 $a$ 满足 $a^2 \le x < (a + 1)^2$，称 $a$ 为 $x$ 的 *整数平方根*。从几何角度来看，整数平方根就是小于 $x$ 的最大正方形的边长。

![](https://pic.leetcode-cn.com/Figures/69/cop.png){:width=480}


#### 方法一：袖珍计算器算法

首先，了解一下[袖珍计算器算法](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Exponential_identity)。

通常，袖珍计算器通过对数表或其他方式计算指数函数和自然对数。那么考虑将求平方根的运算转换为指数运算和对数运算：

$$
\sqrt{x} = e^{\frac{1}{2} \log x} 
$$

此方法中使用到了对数表与其他策略，省略了一部分计算。但实际上对数函数和指数函数本身就是这样计算的。

![](https://pic.leetcode-cn.com/Figures/69/leet.png){:width=480}

```python [solution1-Python]
from math import e, log
class Solution:
    def mySqrt(self, x):
        if x < 2:
            return x
        
        left = int(e**(0.5 * log(x)))
        right = left + 1
        return left if right * right > x else right
```

```java [solution1-Java]
class Solution {
  public int mySqrt(int x) {
    if (x < 2) return x;

    int left = (int)Math.pow(Math.E, 0.5 * Math.log(x));
    int right = left + 1;
    return (long)right * right > x ? left : right;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。

* 空间复杂度：$\mathcal{O}(1)$。


#### 方法二：二叉查找

**思路**

当 $x \ge 2$ 时，它的整数平方根一定小于 $x / 2$ 且大于 0，即 $0 < a < x / 2$。由于 $a$ 一定是整数，此问题可以转换成在有序整数集中寻找一个特定值，因此可以使用二分查找。

![](https://pic.leetcode-cn.com/Figures/69/binary.png)

**算法**

- 如果 `x < 2`，返回 `x`。

- 令左边界为 `2`，右边界为 `x / 2`。

- 当 `left <= right` 时：

    - 令 `num = (left + right) / 2`，比较 `num * num` 与 `x`：

        - 如果 `num * num > x`，更新右边界为 `right = pivot -1`。

        - 如果 `num * num < x`，更新左边界为 `left = pivot + 1`。

        - 如果 `num * num == x`，即整数平方根为 `num`，返回 `num`。

- 返回 `right`。

```python [solution2-Python]
class Solution:
    def mySqrt(self, x):
        if x < 2:
            return x
        
        left, right = 2, x // 2
        
        while left <= right:
            pivot = left + (right - left) // 2
            num = pivot * pivot
            if num > x:
                right = pivot -1
            elif num < x:
                left = pivot + 1
            else:
                return pivot
            
        return right
```

```java [solution2-Java]
class Solution {
  public int mySqrt(int x) {
    if (x < 2) return x;

    long num;
    int pivot, left = 2, right = x / 2;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      num = (long)pivot * pivot;
      if (num > x) right = pivot - 1;
      else if (num < x) left = pivot + 1;
      else return pivot;
    }

    return right;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log N)$。
    使用[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)计算时间复杂度。
    $T(N) = aT\left(\frac{N}{b}\right) + \Theta(N^d)$。 
    该公式表示花费 $\Theta(N^d)$ 时间分解一个问题，得到 $a$ 个规模为 $\frac{N}{b}$ 的子问题。
    在二叉搜索中，每次分解后只有一个子问题 `a = 1`，其规模为初始问题的一半 `b = 2`，每次分解花费恒定时间 `d = 0`，即 $\log_b{a} = d$。
    根据主定理，时间复杂度为 $\mathcal{O}(n^{\log_b{a}} \log^{d + 1} N) = \mathcal{O}(\log N)$。

* 空间复杂度：$\mathcal{O}(1)$。

 
#### 方法三：递归+位操作

**思路**

本方法的思路是使用递归，每一步都减小 $x$，直到 $x < 2$。当 $x < 2$ 时有 $\sqrt{x} = x$ 无需减小。当 $x >= 2$ 时，减小方法如下：

$$
\textrm{mySqrt}(x) = 2 \times \textrm{mySqrt}\left(\frac{x}{4}\right)
$$ 

例如：$\sqrt{x} = 2 \times \sqrt{\frac{x}{4}}$。

减小 $x$ 可以用[左移或右移](https://www.runoob.com/python/python-operators.html#ysf5)实现，因为这种方式计算效率非常高。

$$
x << y \qquad \textrm{表示} \qquad x \times 2^y 
$$

$$
x >> y \qquad \textrm{表示} \qquad \frac{x}{2^y} 
$$

因此，递归式可以重写为：

$$
\textrm{mySqrt}(x) = \textrm{mySqrt}(x >> 2) << 1
$$ 

```python [solution3-Python]
class Solution:
    def mySqrt(self, x):
        if x < 2:
            return x
        
        left = self.mySqrt(x >> 2) << 1
        right = left + 1
        return left if right * right > x else right
```

```java [solution3-Java]
class Solution {
  public int mySqrt(int x) {
    if (x < 2) return x;

    int left = mySqrt(x >> 2) << 1;
    int right = left + 1;
    return (long)right * right > x ? left : right;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log N)$。
    使用[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)计算时间复杂度。
    $T(N) = aT\left(\frac{N}{b}\right) + \Theta(N^d)$。 
    该公式表示花费 $\Theta(N^d)$ 时间分解一个问题，得到 $a$ 个规模为 $\frac{N}{b}$ 的子问题。
    在二叉搜索中，每次分解后只有一个子问题 `a = 1`，其规模为初始问题的一半 `b = 2`，每次分解花费恒定时间 `d = 0`，即 $\log_b{a} = d$。
    根据主定理，时间复杂度为 $\mathcal{O}(n^{\log_b{a}} \log^{d + 1} N) = \mathcal{O}(\log N)$。

* 空间复杂度：$\mathcal{O}(\log N)$，递归栈的深度。

 
#### 方法四：牛顿法

**思路**

计算平方根，最好和使用最多的方法是[牛顿法](https://baike.baidu.com/item/%E7%89%9B%E9%A1%BF%E8%BF%AD%E4%BB%A3%E6%B3%95/10887580?fromtitle=%E7%89%9B%E9%A1%BF%E6%B3%95&fromid=1384129&fr=aladdin)，这里使用不带种子修剪版本的牛顿法简化此问题。查看更多关于[种子修剪](https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Rough_estimation)的知识。

不讨论其数学证明，直接使用牛顿法结论。

$$
x_{k + 1} = \frac{1}{2}\left[x_k + \frac{x}{x_k}\right]
$$ 

如果 $x_0 = x$，则收敛到 $\sqrt{x}$。

最后当误差小于 1 时结束迭代。

```python [solution4-Python]
class Solution:
    def mySqrt(self, x):
        if x < 2:
            return x
        
        x0 = x
        x1 = (x0 + x / x0) / 2
        while abs(x0 - x1) >= 1:
            x0 = x1
            x1 = (x0 + x / x0) / 2        
            
        return int(x1)
```

```java [solution4-Java]
class Solution {
  public int mySqrt(int x) {
    if (x < 2) return x;

    double x0 = x;
    double x1 = (x0 + x / x0) / 2.0;
    while (Math.abs(x0 - x1) >= 1) {
      x0 = x1;
      x1 = (x0 + x / x0) / 2.0;
    }

    return (int)x1;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log N)$，此方法是二次收敛的。

* 空间复杂度：$\mathcal{O}(1)$。

 
#### 比较方法二、三、四

这三种方法的时间复杂度都是 $\mathcal{O}(\log N)$，但它们的性能并不相同。

> 哪种方法执行的迭代次数更少？

由比较每种方法在同一范围下的迭代次数可知，牛顿法的性能最好。

![](https://pic.leetcode-cn.com/Figures/69/cp.png){:width=480}