石子的坐标不要简单看成坐标，如坐标(a, b)要看成域(x)的点(a)和域(y)的点(b)存在联通，因为a,b的数据规模不超过10000，所以可以用b+10000来隔离两个域，这样思考就可以使用一维并查集来做题了。

这里用的是集合的方法来做并查集

```
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        p = collections.defaultdict(set)
        for x, _y in stones:
            y = _y + 10000
            p[x] |= {x}             #初始化
            p[y] |= {y}
            if p[x] != p[y]:        #如果两个集合不相等
                p[x] |= p[y]        #把y集合并进x集合
                for z in p[y]:      
                    p[z] = p[x]     #把y集合里元素指向x集合，总时间复杂度和一般的并查集方法一致
        return len(stones) - len(set(id(c) for c in p.values()))        #石子数量减去并查集指针集合化就可以求出操作次数了
```
