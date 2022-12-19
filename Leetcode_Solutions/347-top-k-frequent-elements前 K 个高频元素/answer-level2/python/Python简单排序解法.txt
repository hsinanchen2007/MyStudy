### 解题思路
先用一个字典统计所有元素及其出现的频率，再将其放入一个列表中，以列表的第二个元素，即频数为关键字，排序

### 代码

```python
from collections import defaultdict
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = defaultdict(int)
        for i in range(len(nums)):
            d[nums[i]] += 1
        tosort = []
        for key in d.keys():
            tosort.append([key, d[key]])
        tosort.sort(key=lambda x: x[1], reverse=True)

        res = []
        for j in range(k):
            res.append(tosort[j][0])

        return res
```