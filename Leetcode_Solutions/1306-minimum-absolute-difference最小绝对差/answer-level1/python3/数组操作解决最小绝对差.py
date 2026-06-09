
```python3
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        temp = [[arr[i], arr[i + 1]] for i in range(len(arr[:-1]))]
        min_ = min([i[1] - i[0] for i in temp])
        return [i for i in temp if i[1] - i[0] == min_]
```