```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        n1 = len(nums)
        n2 = len(nums[0])
        if n1*n2 != r*c:
            return nums
        return [[ nums[(c*(i)+j)//n2 if int((c*(i)+j)/n2)==(c*(i)+j)//n2 else (c*(i)+j)//n2 +1 ][(c*(i)+j)%n2] for j in range(c)]for i in range(r)]
```
