![ed9a61a80ac2fd6d64a2ef857bd1dfe.png](https://pic.leetcode-cn.com/68493d52653999ee942d2735475944e1a66cf9f7ad79a468e0e85ae7eaadb267-ed9a61a80ac2fd6d64a2ef857bd1dfe.png)
target < 0 和 target > 0 的情况是堆成的，看一边就好了
1步能走到1，2步能走到1+2，n步能走到1+2+…+n = n(n+1)/2

还有个规律就是：如果你能走到x，就一定能走到x-2（想象一下第一步不往右走改往左走）, x-4（想象一下第二步不往右走改往左走）……
总结：
0步能达到：0
1步能达到：1
2步能达到：3, 1
3步能达到：6, 4, 2, 0
4步能达到：10, 8, 6, 4, 2, 0
5步能达到：15, 13, 11, 9, 7, 5, 3, 1

代码如下：

```python []
class Solution:
    def reachNumber(self, target: int) -> int:
        import math
        target = abs(target)  ## 因为target<0和target>0是对称的，所以就取绝对值
        n = math.ceil((-1 + math.sqrt(1 + 8 * target)) / 2)  ## 因为n(n+1)/2=target，用求根公式反求n
        while (n * (n + 1) // 2 - target) & 1 == 1:  ## 如果算出来的n算出来的n(n+1)/2和target奇偶性相同，没问题；如果奇偶性不同，n就累加
            n += 1
        return n
```

