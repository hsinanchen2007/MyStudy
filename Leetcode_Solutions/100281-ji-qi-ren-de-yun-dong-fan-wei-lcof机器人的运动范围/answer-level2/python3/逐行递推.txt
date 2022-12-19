### 解题思路

由题意知，除了第一个格子外，机器人到所有可去的格子都至少有这两种方法之一： 向下到达、向右到达。
换句话：如果一个格子可达，那么我们肯定可以从他左边的格子向右走一步过去，或者从他上边的格子向下走一步过去。

这么讲，不是排除从下面去或者从左面去。但是这说明我们只看 向下、向右 就够了。

代码中设置了 ln 标记数组，ln[i] 标识上一行 i 位置机器人能不能到达。初始化为全 False

标记 f 记录当前行有没有可到大达的格子，如果当前行一个可以到的都没有，那么后面的行都不用管了，肯定到不了。

标记 f2 记录该格子的左边紧邻的格子能不能到。f2 初始化为 False。

这样一个格子可以到达，有两个条件： 值满足这个规则、他的上面的格子或者左面的格子可达。


### 代码

```python
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        cnt = 0
        def getv(n):
            v = 0
            for ch in list(str(n)):
                v += int(ch)
            return v
        ln = [False for _ in range(m)]
        for i in range(n):
            v = getv(i)
            f = False
            f2 = False
            nln = [False for _ in range(m)]
            if i == 0: f2 = True
            for j in range(m):
                if getv(j) + v <= k and (f2 or ln[j]):
                    f = True
                    f2 = True
                    nln[j] = True
                    cnt += 1
                else:
                    f2 = False
            ln = nln
            if not f:
                break
        return cnt
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)