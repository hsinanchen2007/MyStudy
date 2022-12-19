1、题目描述

0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

2、思路

（1）递归

先简单的情况，如果n=1，那么剩下的最后一个数字就是0；那么是否可以用递归的思想，将n逐渐减小到1，从而求解呢？

假设，n-1个数字的时候，最后剩下的那个数字是X[n-1]。

那么当有n个数字的时候，先剔除一个数，这个数是m%n-1，剩下n-1个数，由假设知，这n-1个数最后剩下的第X[n-1]+1个数；这n-1个数是从m%n开始的，那么这个序列的第X[n-1]+1个数就是(m%n+X[n-1]+1-1)%n，即
$$
X[n]=(m\%n+X[n-1])\%n=(m+X[n-1])\%n
$$

```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        return 0 if n == 1 else (self.lastRemaining(n - 1, m) + m) % n
```

（2）迭代

可以发现，初值是确定的，也就是0，所以可以用迭代来实现递归

```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # 迭代
        res = 0
        for i in range(1, n):
            res = (res + m) % (i + 1)
        return res
```

