```
class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        s = arr1+arr2+arr3
        res = []
        for ss in set(s):
            if s.count(ss)==3:
                res.append(ss)
        return res
```
