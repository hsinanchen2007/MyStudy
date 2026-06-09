```python
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        # positive numbers
        # Greedy algorithm
        res = 0
        while len(arr) > 1:
            tmpIndex, minVal = 0, float('inf')
            for i in range(len(arr) - 1):
                if arr[i] * arr[i + 1] < minVal:
                    tmpIndex = i
                    minVal = arr[i] * arr[i + 1]
            res += arr[tmpIndex] * arr[tmpIndex + 1]
            arr = arr[:tmpIndex] + [max(arr[tmpIndex], arr[tmpIndex + 1])] + arr[tmpIndex + 2:]
        return res
```