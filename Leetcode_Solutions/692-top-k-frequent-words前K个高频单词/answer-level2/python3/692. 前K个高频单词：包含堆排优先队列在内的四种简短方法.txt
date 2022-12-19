第一个方法理论上最慢，但实际运行起来四个方法都差不太多。

都用到了统计结构：

```py
collections.Counter(words)
```


**方法一**：理论上最慢的$O(nlog(n))$

```python []
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = collections.Counter(words)
        return sorted(c, key = lambda x: [-c[x], x])[: k]
```

**方法二**：不维护队长的手写优先队列$O(nlog(k))$

```python []
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = collections.Counter(words)
        q = []
        for i, s in enumerate(c):
            bisect.insort_left(q, [-c[s], s], hi = min(i, k))
        return [s for _,  s in q[: k]]
```

**方法三**：维护队长的手写优先队列$O(nlog(k))$

```python []
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = collections.Counter(words)
        q = []
        for i, s in enumerate(c):
            bisect.insort_left(q, [-c[s], s])
            if i >= k:
                q.pop()
        return [s for _,  s in q[: k]]
```

**方法四**：系统堆优先队列直接输出$O(nlog(k))$

```python []
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = collections.Counter(words)
        return heapq.nsmallest(k, c, lambda s: [-c[s], s])
```