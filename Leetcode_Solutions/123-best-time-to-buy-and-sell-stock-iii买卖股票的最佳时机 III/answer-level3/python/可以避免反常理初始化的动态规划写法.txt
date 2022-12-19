首先设置了五个不同状态的dp数组，i对应时间期数，X[i]表示X状态下第i期的最大可能受益：
A: 尚未未进行交易
B: 第一次买入到第一次卖出前
C: 第一次卖出到第二次买入前
D: 第二次买入到第二次卖出前
E: 第二次卖出及以后
![image.png](https://pic.leetcode-cn.com/0b48ca483b5642cc5288df2db2e21150d58e5609a0a04e24d9098050afe1c350-image.png)
这里的状态转移方法和图片参考了[@liweiwei1419](/u/liweiwei1419/)大佬，一直很用心写题解也很厉害的大佬，向大佬致敬！
这张图很像一个非随机的马尔科夫链，只能沿A,B,C,D,E方向原地或传播，然而尴尬的地方在于在某些时刻，靠后的状态是不可能存在的，换句话说，只有当i - 1期满足了一些条件，才能使得i期的一些状态存在，如第0期，C, D, E状态都不可能出现。对此一个常规做法是直接赋值为MIN_VALUE，但我觉得既不直观又妨碍整体理解，于是试了试将这些不存在的状态在python中直接初始化为None，并在后续更新过程中分类讨论了该状态是否可能存在的问题，没想到成功了。代码如下：
```
class Solution(object):
    def maxProfit(self, prices):
        if not prices or len(prices) == 1:
            return 0
        n = len(prices)
        A = [0] * n
        B = [0] * n
        C = [0] * n
        D = [0] * n
        E = [0] * n
        A[0] = 0
        B[0] = -prices[0]
        C[0] = None
        D[0] = None
        E[0] = None
        for i in range(1, n):
            A[i] = A[i - 1]
            B[i] = max(B[i - 1], A[i - 1] - prices[i])
            #分类讨论C
            C[i] = max(C[i - 1], B[i - 1] + prices[i]) if C[i - 1] else B[i - 1] + prices[i]
            #分类讨论D
            #下面这里python同学要注意要写成X[i - 1] != None，不要直接写not X[i - 1]
            #否则X[i - 1] = 0的情况也会被考虑进去，造成答案错误
            if C[i - 1] != None and D[i - 1] != None:
                D[i] = max(D[i - 1], C[i - 1] - prices[i])
            elif C[i - 1] != None and D[i - 1] is None:
                D[i] = C[i - 1] - prices[i]
            else:
                D[i] = None
            #分类讨论E
            if D[i - 1] != None and E[i - 1] != None:
                E[i] = max(E[i - 1], D[i - 1] + prices[i])
            elif D[i - 1] != None and E[i - 1] is None:
                E[i] = D[i - 1] + prices[i]
            else:
                E[i] = None
        if E[n - 1]:
            return max(A[n - 1], C[n - 1], E[n - 1])
        if C[n - 1]:
            return max(A[n - 1], C[n - 1])
        return A[n - 1]
```
时间表现没啥影响，空间表现肯定是不好的，但是这样也确实避免了初始化MIN_VALUE难以理解的弊端。
