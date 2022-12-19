要注意的一点是，虽然题目中告诉我们不需要考虑大数问题，但是给出的 `n` 可以取到 $-2147483648$（整型负数的最小值），因此，在编码的时候，需要将 `n` 转换成 `long` 类型。

### 写法一：递归写法（分治思想）

**参考代码 1**：

说明：Java 与 Python 的写法在小细节上有所不同，本质都是分治的思想。只是本人为了练习采用不同的写法，与语言本身无关。

```Java []
public class Solution {

    public double myPow(double x, int n) {
        // 特判，也可以认为是递归终止条件
        long N = n;
        if (N < 0) {
            return 1 / myPow(x, -N);
        }
        return myPow(x, N);
    }

    private double myPow(double x, long n) {
        if (n == 0) {
            return 1;
        }

        if (x == 1) {
            return 1;
        }

        // 根据指数是奇数还是偶数进行分类讨论
        // 使用位运算的 与 运算符代替了求余数运算

        if ((n & 1) == 0) {
            // 分治思想：分
            double square = myPow(x, n >>> 1);
            // 分治思想：合，下面同理
            return square * square;
        } else {
            // 是奇数的时候
            double square = myPow(x, (n - 1) >>> 1);
            return square * square * x;
        }
    }
}
```
```Python []
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1

        if n < 0:
            return 1 / self.myPow(x, -n)

        # 如果是奇数
        if n & 1:
            return x * self.myPow(x, n - 1)
        return self.myPow(x * x, n >> 1)
```


### 写法二：非递归写法（将指数看成二进制数）

把指数 `n` 做“二进制分解”，**在底数不断自身乘以自身的过程中，将最终结果需要的部分保存下来**。


![image.png](https://pic.leetcode-cn.com/ab780b00a05f762c87ae4c68e74ef8d3a8b961a98762c02b61585d8f8c61747c-image.png)

**参考代码 2**：

```Java []
public class Solution {

    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N *= -1;
        }

        double res = 1;
        while (N > 0) {
            if ((N & 1) == 1) {
                res *= x;
            }

            x *= x;
            N >>>= 1;
        }
        return res;
    }
}
```
```Python []
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            # 负数变成正数
            n = -n

        res = 1
        while n:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res
```