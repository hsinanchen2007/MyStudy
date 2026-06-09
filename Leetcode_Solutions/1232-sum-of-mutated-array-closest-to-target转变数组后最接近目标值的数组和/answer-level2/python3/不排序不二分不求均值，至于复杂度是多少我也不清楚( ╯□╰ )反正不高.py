```
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        leastDiff = float("inf")
        res = [target//len(arr)]
        while True:
            lessThanTemp = [n for n in arr if n < res[-1]]
            howManyLarger = len(arr) - len(lessThanTemp)
            diff = abs(sum(lessThanTemp) + res[-1] * howManyLarger - target)
            if diff >= leastDiff:
                return res[-2]
            leastDiff = diff
            res.append(res[-1] + max(diff // howManyLarger, 1))
```
