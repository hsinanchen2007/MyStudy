![image.png](https://pic.leetcode-cn.com/a70cadd2fb53d8d728d83cf8e5124af86af34f9778dae7e08f951be49af61cb1-image.png)

```python []
class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        a, d = sorted(nums, reverse = True), {}
        for i, v in enumerate(a):
            if i > 2:
                d[v] = str(i + 1)
            elif i == 0:
                d[v] = "Gold Medal"
            elif i == 1:
                d[v] = "Silver Medal"
            elif i == 2:
                d[v] = "Bronze Medal"
        return [d[v] for v in nums]
```
