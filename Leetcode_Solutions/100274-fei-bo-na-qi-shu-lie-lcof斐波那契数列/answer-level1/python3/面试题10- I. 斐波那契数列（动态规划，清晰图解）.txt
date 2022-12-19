#### 解题思路：

斐波那契数列的定义是 $f(n + 1) = f(n) + f(n - 1)$ ，生成第 $n$ 项的做法有以下几种：
1. **递归法：**
    - **原理：** 把 $f(n)$ 问题的计算拆分成 $f(n-1)$ 和 $f(n-2)$ 两个子问题的计算，并递归，以 $f(0)$ 和 $f(1)$ 为终止条件。
    - **缺点：** 大量重复的递归计算，例如 $f(n)$ 和 $f(n - 1)$ 两者向下递归需要 **各自计算** $f(n - 2)$ 的值。
2. **记忆化递归法：**
    - **原理：** 在递归法的基础上，新建一个长度为 $n$ 的数组，用于在递归时存储 $f(0)$ 至 $f(n)$ 的数字值，重复遇到某数字则直接从数组取用，避免了重复的递归计算。
    - **缺点：** 记忆化存储需要使用 $O(N)$ 的额外空间。
3. **动态规划：**
    - **原理：** 以斐波那契数列性质 $f(n + 1) = f(n) + f(n - 1)$ 为转移方程。
    - 从计算效率、空间复杂度上看，动态规划是本题的最佳解法。

> 下图帮助理解递归法的 “重复计算” 概念。

![Picture0.png](https://pic.leetcode-cn.com/25e913ab8d7a22bb017669e4a097cf51d10861f365002f2d8556ee7a64464cd8-Picture0.png){:width=450}

#### 动态规划解析：

- **状态定义：** 设 $dp$ 为一维数组，其中 $dp[i]$ 的值代表 斐波那契数列第 $i$ 个数字 。
- **转移方程：** $dp[i + 1] = dp[i] + dp[i - 1]$ ，即对应数列定义 $f(n + 1) = f(n) + f(n - 1)$ ；
- **初始状态：** $dp[0] = 0$, $dp[1] = 1$ ，即初始化前两个数字；
- **返回值：** $dp[n]$ ，即斐波那契数列的第 $n$ 个数字。

#### 空间复杂度优化：

> 若新建长度为 $n$ 的 $dp$ 列表，则空间复杂度为 $O(N)$ 。
- 由于 $dp$ 列表第 $i$ 项只与第 $i-1$ 和第 $i-2$ 项有关，因此只需要初始化三个整形变量 `sum`, `a`, `b` ，利用辅助变量 $sum$ 使 $a, b$ 两数字交替前进即可 *（具体实现见代码）* 。
- 节省了 $dp$ 列表空间，因此空间复杂度降至 $O(1)$ 。

#### 循环求余法：

> **大数越界：** 随着 $n$ 增大, $f(n)$ 会超过 `Int32` 甚至 `Int64` 的取值范围，导致最终的返回值错误。 
- **求余运算规则：** 设正整数 $x, y, p$ ，求余符号为 $\odot$ ，则有 $(x + y) \odot p = (x \odot p + y \odot p) \odot p$ 。
- **解析：** 根据以上规则，可推出 $f(n) \odot p = [f(n-1) \odot p + f(n-2) \odot p] \odot p$ ，从而可以在循环过程中每次计算 $sum = (a + b) \odot 1000000007$ ，此操作与最终返回前取余等价。

> 图解基于 Java 代码绘制，Python 由于语言特性可以省去 $sum$ 辅助变量和大数越界处理。

<![Picture1.png](https://pic.leetcode-cn.com/f653118d5c80fc44dde284c9b9c4f2d2115916f0123e384733526279f9b23302-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/944b51e8d97de5dbf4a1f32f94d41ee5ff3f02512a84a992b4c135898c32c160-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/271f93032bfd5752680da62bf4d877912ec7c4b765010c7123f7238128bc254e-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/02b84032f8d87224f641bde39a1dbad9d50936edd034bd8f14fa221452b38e27-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/ab56d9401cd08e549cebb2351fddf3d9fd40648bbc105e14eeb954ba37e955ec-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/16681ab7512ff7f9bdf8f7102556a848ec780815723573a3b6e0344e68db7f52-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/a4a65c8b160832c871f25ba011d383b8b8ad2956bfab5843ced6b56f61be2ea7-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/d517868e871c4ac19a47b18daf59ce98e58f120c1dac49b24b2a5464dec980d5-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/44f7aa4feb3a2e082417ac809307b55d654b691d5472c23eb11841ff58f8c3ed-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/9a3bd335f639944934521425e9f515107310f00a92fb91d4fb7d74b2db8141ce-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/854d5bcd36a4c394f51eefd70d716b272f8582c9b5e1d3d08fb3c5e823850c9d-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/2709b0d93a274f38735656d993f3444e05f6b5fcfd79d0b8d5a078ae33c86d07-Picture12.png)>

#### 复杂度分析：

- **时间复杂度 $O(N)$ ：** 计算 $f(n)$ 需循环 $n$ 次，每轮循环内计算操作使用 $O(1)$ 。
- **空间复杂度 $O(1)$ ：** 几个标志变量使用常数大小的额外空间。

#### 代码：

> 由于 Python 中整形数字的大小限制 *取决计算机的内存* （可理解为无限大），因此可不考虑大数越界问题。

```python []
class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return a % 1000000007
```

```java []
class Solution {
    public int fib(int n) {
        int a = 0, b = 1, sum;
        for(int i = 0; i < n; i++){
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
}
```