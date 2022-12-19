```python
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 2:
            return []
        outs = collections.defaultdict(int)
        for i in nums:
            c = []
            for j in outs:
                if i >= j[-1]:
                    c.append(tuple([_ for _ in j] + [i]))
            for _ in c:
                outs[_] += 1
            outs[tuple([i])] += 1
        return [i for i in outs if len(i) > 1]
```
