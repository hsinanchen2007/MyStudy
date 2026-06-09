### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
    #如果行列数乘积与原矩阵不相等，则无法构造，直接输出原矩阵。如果相等，则把原矩阵先转化为一个列表
    #然后根据新矩阵的列数进行切片，再将切好的片作为新矩阵的行，重构矩阵
        if len(nums) * len(nums[0]) != r * c:
            return nums
        else:
            origin = []
            for i in range(len(nums)):
                origin += nums[i]
            res = []
            for i in range(r):
                res.append(origin[i*c:i*c+c])
            return res



```