```python3
    def findContentChildren(self, g, s):
        g.sort() #孩子数组
        s.sort() #饼干数组
        child = 0 #孩子 i
        cookie = 0 #饼干 j
        while child < len(g) and cookie < len(s):
            if g[child] <= s[cookie]: #能够满足一个孩子的胃口
                child += 1 #孩子饱了
            cookie += 1 #饼干吃了
        return child #返回被满足的孩子数
```
