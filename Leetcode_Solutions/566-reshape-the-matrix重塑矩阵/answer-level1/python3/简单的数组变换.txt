### 解题思路
1.先考虑是否可以变换
2.进行变换。根据新数组和旧数组下标排列规则可得，新数组行下标i，列下标j等于旧数组nums的(i*c+j)//len(nums[0])，(i*c+j)%len(nums[0])

### 代码

```python3
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if r * c != len(nums) * len(nums[0]):
            return nums
        res = [[0 for _ in range(c)] for _ in range(r)]
        for i in range(r):
            for j in range(c):
                res[i][j] = nums[(i*c+j)//len(nums[0])][(i*c+j)%len(nums[0])]
        return res
```