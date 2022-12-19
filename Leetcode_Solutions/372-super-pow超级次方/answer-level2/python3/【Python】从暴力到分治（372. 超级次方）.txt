# 暴力（超时）
## 思路

这道题和[50.pow-x-n](https://github.com/azl397985856/leetcode/blob/master/problems/50.pow-x-n.md) 有点像，我直接复用代码。思路不清楚的可以先看下我的那篇文章，以下我会直接使用myPow，你可以把它当成系统内置的pow函数。

我们的思路是对b逐位计算myPow，然后结果相乘即可。 比如 a = 2, b = [1, 0]。

- 先计算 2 ** 0 = 1
- 再计算 2 ** 10 = 1024
- 相乘为 1 * 1024 = 1024

为了防止数值溢出，我们使用一个小技巧，即`(a * b) % k = (a % k) * (b % k) % k`

## 代码
```python
class Solution:
    def myPow(self, x: int, n: int) -> int:
        if n < 0:
            return 1 / self.myPow(x, -n)
        ans = 1
        while n:
            if n & 1 == 1:
                ans *= x
            x *= x
            n >>= 1
        return ans

    def superPow(self, a: int, b: List[int]) -> int:
       	ans = 1
        mask = 1
        k = 1337
        for num in b[::-1]:
            ans = (ans % k) * (self.myPow(a, num * mask) % k) % k
            mask *= 10
        return ans
```

# 分治

## 思路

上面代码比较暴力。 实际上，对于 a = 2, b = [1, 0, 0, 0]。（以下简称f(2, 1000)）我们上面的方案会计算:

- 2 ** 0 = 1
- 2 ** 0 = 1
- 2 ** 0 = 1
- 2 ** 1000 = ...

而我们知道 f(2, 1000) 等价于 f(2, 100) * f(2, 10) 这样计算量就小了很多。 有了这个思路，我们可以使用递归的方式简单解决。

## 代码

```python
class Solution:
    def myPow(self, x: int, n: int) -> int:
        if n < 0:
            return 1 / self.myPow(x, -n)
        ans = 1
        while n:
            if n & 1 == 1:
                ans *= x
            x *= x
            n >>= 1
        return ans

    def superPow(self, a: int, b: List[int]) -> int:
        if not b: return 1
        k = 1337
        return (self.myPow(a, b.pop(-1)) % k) * (self.myPow(self.superPow(a, b) % k, 10) % k) % k
```

# 扩展
你可以使用迭代的方式来解决么？


更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)