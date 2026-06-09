执行用时 :44 ms, 在所有 Python3 提交中击败了100.00% 的用户。
内存消耗 :16.8 MB, 在所有 Python3 提交中击败了63.94%的用户。

```
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l = 0
        n = len(citations)
        r = n - 1
        res = 0
        while l <= r:
            mid = (l + r) // 2
            tmp = n - mid
            if citations[mid] >= tmp:
                res = tmp
                r = mid - 1
            else:
                l = mid + 1
        return res
```
