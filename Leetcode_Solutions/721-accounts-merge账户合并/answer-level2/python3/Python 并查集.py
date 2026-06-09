```python
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        d = collections.defaultdict(set)
        c = set()
        n = len(accounts)
        for i in range(n):
            for j in accounts[i][1:]:   #统计邮箱出现在哪些账户
                for k in d[j]:
                    if i != k:
                        c |= {(k, i)}   #把判断两个账户是否能够相连哈希化
                d[j] |= {i}
        p = [*range(n)]                 #并查集初始化
        def f(x):                       #并查集修改函数
            if p[x] != x:
                p[x] = f(p[x])
            return p[x]
        for i in range(n):
            for j in range(i + 1, n):
                if (i, j) in c:
                    pi, pj = f(i), f(j)
                    if pi != pj:        #符合条件的合并集合编号
                        p[pj] = pi
        ans = {}
        for i in range(n):              #按集合编号合并元素
            pi = f(i)
            if pi not in ans:
                ans[pi] = accounts[i]
            else:
                ans[pi] += accounts[i][1:]
        return [[s[0]] + sorted(list(set(s[1:]))) for s in ans.values()]        #邮箱列表去重并排序输出
```
