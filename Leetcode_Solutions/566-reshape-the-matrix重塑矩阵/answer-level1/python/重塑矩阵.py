### 解题思路
重塑矩阵

### 代码

```python3
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if len(nums) == 0:
            return nums
        col = len(nums) * len(nums[0])
        ret = []
        if r * c != col:
            return nums
        else:
            tempI, tempJ = 0, 0
            for i in range(r):
                ret.append([])
                for j in range(c):
                    ret[i].append(nums[tempI][tempJ])
                    if tempJ < len(nums[0]) - 1:
                        tempJ += 1
                    else:
                        tempI, tempJ = tempI + 1, 0
        return ret
                
```