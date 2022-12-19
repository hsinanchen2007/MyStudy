思路分析（个人理解，只是记录下来 hha）：
    1.斐波那契常规处理中(倒序计算)会重复计算，这也是时间消耗较长的原因
    2.利用动态规划正序推导，计算每一项的值（虽然利用前两项的值，但由于列表已经保存，直接索引就可以获得）
    3.循环(终止条件:<=N 从2开始>)，然后输出最后一个值就是当前项的值
```
class Solution(object):
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N == 0:
            return 0
        elif N == 1:
            return 1
        opt = [0] * (N+1)
        opt[0] = 0
        opt[1] = 1
        i = 2
        while i <= N:
            opt[i] = opt[i-1] + opt[i-2]
            i += 1
        return opt[-1]
```
常规递归：
```
        if N == 0:
            return 0
        elif N == 1:
            return 1
        else:
            return self.fib(N-1) + self.fib(N-2)
```
