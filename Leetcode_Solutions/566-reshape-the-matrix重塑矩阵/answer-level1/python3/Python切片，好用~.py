先把原矩阵转成数组，再根据目标矩阵的列数进行切片。
```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m,n=len(nums),len(nums[0])
        if m*n!=r*c:
            return nums
        res=[i for j in nums for i in j]    
        return [res[i:i+c] for i in range(0,len(res),c)]
```
