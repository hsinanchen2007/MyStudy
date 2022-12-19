```python
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if r*c != len(nums)*len(nums[0]):
            return nums
        
        def flatten(obj):
            for ele in obj:
                if isinstance(ele, list):
                    yield from flatten(ele)
                else:
                    yield ele
                       

        it, result = flatten(nums), []
        for i in range(r):
            row = []
            for j in range(c):
                row.append(next(it))
            result.append(row)
                
        return result
```
