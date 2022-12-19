```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = collections.defaultdict(list)
        for s in strs:
            st = ''.join(sorted(s))
            res[st].append(s)
        return [value for _, value in res.items()]

```