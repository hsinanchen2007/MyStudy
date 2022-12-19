几行代码
列表推导式写起来方便，但是可读性很差...

```python []
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        most_num = collections.Counter(nums).most_common(1)[0][1]
        dct = collections.defaultdict(list)
        for i,v in enumerate(nums):
            dct[v].append(i)
        return min(index_list[-1]-index_list[0]+1 for val,index_list in dct.items() if len(index_list) == most_num)
```
