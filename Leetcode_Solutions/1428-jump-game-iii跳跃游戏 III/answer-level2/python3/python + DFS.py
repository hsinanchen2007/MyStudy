```python
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        # arr.length <= 5 * 10 ** 4
        # visited set
        # Time complexity: O(N)
        # Space complexity: O(1)
        res = False 
        def dfs(i):
            nonlocal res
            if arr[i] < 0 or res: return 
            if arr[i] == 0:
                res = True
                return
            tmp = arr[i]
            arr[i] = -1
            if i - tmp >= 0: dfs(i - tmp)
            if i + tmp <= len(arr) - 1: dfs(i + tmp)
        dfs(start)
        return res
```