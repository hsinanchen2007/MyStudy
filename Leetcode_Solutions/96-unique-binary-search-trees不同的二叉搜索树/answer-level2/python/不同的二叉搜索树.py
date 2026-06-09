
#### 方法一：动态规划

**直觉**

本问题可以用动态规划求解。

给定一个有序序列 `1 ... n`，为了根据序列构建一棵二叉搜索树。我们可以遍历每个数字 `i`，将该数字作为树根，`1 ... (i-1)` 序列将成为左子树，`(i+1) ... n` 序列将成为右子树。于是，我们可以递归地从子序列构建子树。
在上述方法中，由于根各自不同，每棵二叉树都保证是独特的。

可见，问题可以分解成规模较小的子问题。因此，我们可以存储并复用子问题的解，而不是递归的（也重复的）解决这些子问题，这就是动态规划法。

**算法**

问题是计算不同二叉搜索树的个数。为此，我们可以定义两个函数：

1. $G(n)$: 长度为`n`的序列的不同二叉搜索树个数。

2. $F(i, n)$: 以i为根的不同二叉搜索树个数($1 \leq i \leq n$)。

可见，
>$G(n)$ 是我们解决问题需要的函数。


稍后我们将看到，$G(n)$ 可以从 $F(i, n)$ 得到，而 $F(i, n)$ 又会递归的依赖于 $G(n)$。

首先，根据上一节中的思路，不同的二叉搜索树的总数 $G(n)$，是对遍历所有 `i` (`1 <= i <= n`) 的 $F(i, n)$ 之和。换而言之：

$$
G(n) = \sum_{i=1}^{n} F(i, n) \qquad  \qquad (1)
$$

特别的，对于边界情况，当序列长度为 1 （只有根）或为 0 （空树）时，只有一种情况。亦即：

$$
G(0) = 1, \qquad G(1) = 1
$$

给定序列 `1 ... n`，我们选出数字 `i` 作为根，则对于根 i 的不同二叉搜索树数量 $F(i, n)$，是左右子树个数的**笛卡尔积**，如下图所示:

![image.png](https://pic.leetcode-cn.com/fe9fb329250b328bb66032dda25b867e0047fcb480c2c0bcf14ecc2a4c12e454-image.png){:width=500}
{:align=center}

举例而言，$F(3, 7)$，以 `3` 为根的不同二叉搜索树个数。为了以 `3` 为根从序列 `[1, 2, 3, 4, 5, 6, 7]` 构建二叉搜索树，我们需要从左子序列 `[1, 2]` 构建左子树，从右子序列 `[4, 5, 6, 7]` 构建右子树，然后将它们组合(即笛卡尔积)。
巧妙之处在于，我们可以将 `[1,2]` 构建不同左子树的数量表示为 $G(2)$, 从 [4, 5, 6, 7]` 构建不同右子树的数量表示为 $G(4)$。这是由于 $G(n)$ 和序列的内容无关，只和序列的长度有关。于是，$F(3,7) = G(2) \cdot G(4)$。 概括而言，我们可以得到以下公式：

$$
F(i, n) = G(i-1) \cdot G(n-i) \qquad  \qquad (2)
$$

将公式 (1)，(2) 结合，可以得到 $G(n)$ 的递归表达公式：

$$
G(n) = \sum_{i=1}^{n}G(i-1) \cdot G(n-i) \qquad  \qquad (3)
$$

为了计算函数结果，我们从小到大计算，因为 $G(n)$ 的值依赖于 $G(0) … G(n-1)$。

根据以上的分析和公式，很容易实现计算 $G(n)$ 的算法。 下面是示例:

```Java [solution 1]
public class Solution {
  public int numTrees(int n) {
    int[] G = new int[n + 1];
    G[0] = 1;
    G[1] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        G[i] += G[j - 1] * G[i - j];
      }
    }
    return G[n];
  }
}
```
```Python [solution 1]
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        G = [0]*(n+1)
        G[0], G[1] = 1, 1

        for i in range(2, n+1):
            for j in range(1, i+1):
                G[i] += G[j-1] * G[i-j]

        return G[n]
```


**复杂度分析**

* 时间复杂度 : 上述算法的主要计算开销在于包含 `G[i]` 的语句。因此，时间复杂度为这些语句的执行次数，也就是 $\sum_{i=2}^{n} i = \frac{(2+n)(n-1)}{2}$。因此，时间复杂度为 $O(N^2)$。

* 空间复杂度 : 上述算法的空间复杂度主要是存储所有的中间结果，因此为 $O(N)$。

<br/>

---
 

#### 方法二：数学演绎法

**I直觉**

事实上 $G(n)$函数的值被称为 [卡塔兰数](https://baike.baidu.com/item/catalan/7605685?fr=aladdin) $C_n$。卡塔兰数更便于计算的定义如下:

$$
C_0 = 1, \qquad C_{n+1} = \frac{2(2n+1)}{n+2}C_n \qquad  \qquad (4)
$$

证明过程可以参考上述文献，此处略去。

**算法**

有了公式 (4)， 计算 $G_n$/$C_n$ 十分容易。以下为示例:

```Java [solution 2]
class Solution {
  public int numTrees(int n) {
    // Note: we should use long here instead of int, otherwise overflow
    long C = 1;
    for (int i = 0; i < n; ++i) {
      C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int) C;
  }
}
```

```Python [solution 2]
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        C = 1
        for i in range(0, n):
            C = C * 2*(2*i+1)/(i+2)
        return int(C)
```

**复杂度分析**

* 时间复杂度 : $O(N)$，只有一层循环。
* 空间复杂度 : $O(1)$，只需要一个变量来存储中间与最终结果。

