![image.png](https://pic.leetcode-cn.com/3b586d8646bcd3fb8622ebd99e1f161f1c86510f655a73241e5d97aaf270e7b3-image.png)


```
'''
贪心策略
数值一样的位置不用变动，直接先排除掉
然后统计(x, y), (y, x)两种二元组出现的次数
两个(x, y)或者两个(y, x)交换一次可以变成一样的消掉
最后如果(x, y)和(y, x)在两两配对后分别都还剩一个，还需要额外两次交换
'''

from collections import Counter
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        c = Counter()
        c[('x', 'y')] = 0
        c[('y', 'x')] = 0
        for ch1, ch2 in zip(s1, s2):
            if ch1 != ch2:
                c[(ch1, ch2)] += 1

        cnt = list(c.values())
        if sum(cnt) % 2 == 1:
            return -1

        ans = cnt[0] // 2 + cnt[1] // 2
        if cnt[0] % 2 == 1:
            ans += 2

        return ans
```
