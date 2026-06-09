平时做的并查集基本上都是利用列表（数组）的下标和数字，此题转换到字典键值即可。
```
class Solution(object):
    def trulyMostPopular(self, names, synonyms):
        # 预处理
        f, cnt = {}, {}
        for name in names:
            n, c = name.split("(")
            f[n], cnt[n] = n, int(c[:-1])
        
        # 并查集查找同类根
        def find(x):
            if f[x] <> x: f[x] = find(f[x])
            return f[x]

        for synonym in synonyms:
            name1, name2 = synonym.split(",")
            # 如果当前同类名不在公布名单中，则跳过
            if f.get(name1[1:]) is None or f.get(name2[:-1]) is None: continue
            p1, p2 = find(name1[1:]), find(name2[:-1])
            # 保证同类根的字典序最小
            if p1 > p2: f[p1] = p2
            else: f[p2] = p1
        
        # 统计总频率
        ans = collections.defaultdict(int)
        for k, v in f.iteritems():
            ans[find(v)] += cnt[k]
        
        return [k+'('+str(v)+')' for k, v in ans.iteritems()]
```
