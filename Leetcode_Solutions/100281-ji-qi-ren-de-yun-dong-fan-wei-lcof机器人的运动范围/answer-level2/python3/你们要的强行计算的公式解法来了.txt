我们把数据若干个分成`10*10`的方块，如果不足`10`就按实际的数值算，然后计算每块中可以走到的方格数，这就是`calc_blocks`函数。
它分三种情况，
1. 走不到`i > 0 and i + 8 > k`，那就返回0；
2. `10*10`的，用`count_stairs`函数来计算，就是两个等差数列；
3. 不足`10`，那就枚举，由于数值不大，简单枚举就行了。

执行结果：通过 显示详情
执行用时 : 44 ms, 在所有 Python3 提交中击败了98.62%的用户
内存消耗 : 13.7 MB, 在所有 Python3 提交中击败了100.00%的用户

这道题提交了多次，是因为边界条件太多了。
```Python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def count_stairs(n):
            if n <= 10:
                return n * (n + 1) // 2
            elif n > 20:
                return 100
            else:
                s = (n - 10) * (29 - n) // 2
                return s + 55

        def calc_block(i, k, m1=10, n1=10):
            if i > 0 and i + 8 > k:
                return 0
            if m1 == 10 and n1 == 10:
                return count_stairs(k - i + 1)
            else:
                res = 0
                for m in range(m1):
                    for n in range(i, i + n1):
                        if m + n <= k:
                            res += 1
                return res

        import math
        m10 = math.ceil(m / 10)
        m10r = m % 10
        n10 = math.ceil(n / 10)
        n10r = n % 10
        res = 0
        for m in range(m10):
            m1 = 10 if m < m10 - 1 or m10r == 0 else m10r
            for n in range(n10):
                n1 = 10 if n < n10 - 1 or n10r == 0 else n10r
                # print(f'calc_block({m}+{n}, {k}, {m1}, {n1}) = {calc_block(m + n, k, m1, n1)}')
                res += calc_block(m + n, k, m1, n1)
        return res
```
