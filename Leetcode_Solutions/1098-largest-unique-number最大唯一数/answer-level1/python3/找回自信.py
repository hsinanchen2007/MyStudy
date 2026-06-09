

```python3
class Solution:
    def largestUniqueNumber(self, A: List[int]) -> int:
        ans = []
        for k, v in dict(collections.Counter(A)).items():
            if v == 1:
                ans.append(k)
        if ans:
            return max(ans)
        else:
            return -1

```