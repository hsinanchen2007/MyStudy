

理论上时间复杂度是$O({N}^{2})$，但向量操作太多了，所以非常慢，需要的话的可以把`cross`和`norm`以及向量加减法单独写出来大概就快了。

后来还想试试复数法，结果看了官解发现就是复数法，还一样用了`collections`和`itertools`模块，那就不写了，不过没想到的是几乎相同的结构，复数法能比`numpy`向量法快这么多。

另外官解的复杂度计算似乎是有问题，相同类型的枚举上界是$logN$，那同类点的数量就不应该是${N}^{2}$了吧，复杂度肯定小于$O({N}^{2}logN)$，或者说，第二次循环的枚举元素肯定来自于第一次遍历，所以复杂度应该还是$O({N}^{2})$。

另外注意的一点是官解用的是python2，`iteritems`在py3已经不用了，py3默认返回的都是迭代器。

```python []
import numpy
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        cro, nor = numpy.cross, numpy.linalg.norm           #cro叉积，nor向量的模
        points = [*map(numpy.array, points)]                #向量初始化
        ans, d = float('inf'), collections.defaultdict(list)#字典列表初始化
        for x, y in itertools.combinations(points, 2):      #遍历点点组合
            p, q = tuple(x + y), nor(x - y)                 #向量的和进行哈希化，向量求模
            d[p, q] += [x - y]                              #把两点的差，存入字典
        for idxs in d.values():                             #遍历字典
            for x, y in itertools.combinations(idxs, 2):    #遍历对应列表的点点组合
                ans = min(ans, abs(cro(x, y)))              #找出最小叉积
        return ans / 2 if ans < float('inf') else 0         #之前算中心坐标的时候没有除二，在输出这里除二了。
```
