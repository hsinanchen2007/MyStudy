![a592e3c423c699374c5d8ef4d47b163.png](https://pic.leetcode-cn.com/5e9b005fcf9284ed4b9bebde9bf631aba1e85d80334fefee09c08d1f9492d931-a592e3c423c699374c5d8ef4d47b163.png)

```python []
class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        import collections
        dic = collections.defaultdict(set)
        for i, num in enumerate(B):
            dic[num].add(i)
        res = []
        for num in A:
            res.append(dic[num].pop())
        return res
```

