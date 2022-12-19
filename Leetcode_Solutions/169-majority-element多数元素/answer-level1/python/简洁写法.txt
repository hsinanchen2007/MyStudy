目的是找到序列中出现最多的元素
那么可以用字典存储“元素-次数”
并且返回次数最大的key即可
```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d=dict(collections.Counter(nums))
        return max(d,key=d.get)
```
