```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [k for k, v in collections.Counter(nums).most_common(k)]
```
Counter类的目的是用来跟踪值出现的次数。它是一个无序的容器类型，以字典的键值对形式存储，其中元素作为key，其计数作为value
- 非内置解法：
```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for n in nums:
            d[n] = d.get(n, 0) + 1
        return sorted(d.keys(), key=d.get)[-k:]
```
