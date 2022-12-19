这个远远没有题库里的第 6 题 [Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion) 难，这题很靠前，估计很多人都做过吧。

本题目尤其用 python 方便，连去结尾空格都有函数。

```python
class Solution:
    def printVertically(self, s: str) -> List[str]:
        s = s.split(' ')
        max_l = 0
        for w in s:
            max_l = max(max_l, len(w))
        r = [[] for i in range(max_l)]
        for w in s:
            for i in range(max_l):
                if i < len(w):
                    r[i].append(w[i])
                else:
                    r[i].append(' ')
        rr = []
        for x in r:
            rr.append(''.join(x).rstrip())
        return rr
```


欢迎访问我的博客 [https://codeplot.top/](https://codeplot.top/)

我的博客的[刷题分类](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)