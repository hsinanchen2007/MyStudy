### 解题思路
使用两个 Counter 分别统计 s 和 t 中出现的各个字母的数量。

只看 t 中比 s 多的字母，一共多多少，加起来就是答案

### 代码

```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        import collections
        c1 = collections.Counter(s)
        c2 = collections.Counter(t)
        ans = 0
        for c in c2:
            if c not in c1:
                ans += c2[c]
            else:
                if c2[c] > c1[c]:
                    ans += c2[c] - c1[c]
        return ans
```

欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)
