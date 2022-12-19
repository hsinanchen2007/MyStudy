![image.png](https://pic.leetcode-cn.com/cc6f24e1ca069335ad9619c93fb89242cf240cd83415f25014d19070f7acf8eb-image.png)

基础写法：

```python []
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        h = {}      #建立AB和的哈希映射
        for a in A:
            for b in B:
                if -a -b in h:
                    h[-a - b] += 1
                else:
                    h[-a - b] = 1
        return sum(h[c + d] for c in C for d in D if c + d in h)      #输出时要做键值判断
```

使用collections.defaultdict(int)的写法，本质上和上面是一样的，目前来看这种最快，但速度区别不明显：

```python []
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        h = collections.defaultdict(int)
        for a in A:
            for b in B:
                h[-a - b] += 1
        return sum(h[c + d] for c in C for d in D)
```

再简洁点，如果纯粹计数的话，可以用collections.Counter()，但后两种对键值无需作存在判断，但加判断会提高sum求和的效率：

```python []
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        h = collections.Counter(-a - b for a in A for b in B)
        return sum(h[c + d] for c in C for d in D)
```
