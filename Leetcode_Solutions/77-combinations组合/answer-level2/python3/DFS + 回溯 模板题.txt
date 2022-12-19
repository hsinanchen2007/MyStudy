```py3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        def completePermutation(tmp, idx):
            if len(tmp) == k:
                ans.append(tmp[:])
            for i in range(idx, n + 1):
                tmp.append(i)
                completePermutation(tmp, i + 1)
                tmp.pop()
        completePermutation([], 1)
        return ans 
```