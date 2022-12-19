先做数组元素的计数，再按字典的值进行排序，再依次获取相应的数值元素

```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        match = {}
        for i in nums:
            if match.get(i):
                match[i] += 1
            else:
                match[i] = 1
        match = sorted(match.items(), key = lambda x: x[1])
        res = []
        for i in range(1, k+1):
            res.append(match[-i][0])
        return res
```
