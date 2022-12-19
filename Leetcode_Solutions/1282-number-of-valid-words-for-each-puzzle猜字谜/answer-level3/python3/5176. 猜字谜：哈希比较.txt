原理还是匹配，但直接暴力判断肯定超时，解决方法通常有两种，一种是位运算比较，另一种就是去重排序后存进字典或集合哈希比较，这里用的方法是后者哈希比较的方法。

时间复杂度：$O(\sum WlogW + {2}^{6}\sum PlogP)$ ，其中$W=words[i].length$，$P=puzzles[i].length$。

![image.png](https://pic.leetcode-cn.com/76b2c0709fb2163cb93bbe66cf81404c539ffb7f628f43eb90d8fec766a8619a-image.png)

920ms，时间仅供参考。

```python []
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        d = collections.Counter(''.join(sorted({*w})) for w in words if len({*w}) <= 7)   #把谜底去重排序并合并计数
        def f(p):
            cbt = [p[0]]            #谜面首元素必须放进组合
            for c in p[1: ]:        #谜面除首元素外，其他元素0-1状态放进组合排好序，以匹配处理后的谜底
                cbt += [''.join(sorted(s + c)) for s in cbt]
            return sum(d[s] for s in cbt if s in d) #如果谜面可以匹配谜底，就加上这种类型的谜底的数量
        return [*map(f, puzzles)]
```

参考了大佬`frozenset()`的函数，改进了一下，少了排序这一步确实更快了，时间复杂度：$O(\sum W + {2}^{6}\sum P)$：

![image.png](https://pic.leetcode-cn.com/8198e70c5a66b8033d22fc8b6b3532c282be73b6fd9ba30683a1d87856b8b55d-image.png)

804ms，仅供参考。

```python []
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        d = collections.Counter(filter(lambda w: len(w) <= 7, map(frozenset, words))) #改成了过滤函数
        def f(p):
            cbt = [p[0]]
            for c in sorted(p[1: ]):
                cbt += [s + c for s in cbt]
            return sum(d[s] for s in map(frozenset, cbt) if s in d)
        return [*map(f, puzzles)]
```
