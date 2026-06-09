### 解题思路
先按行统计所有元素
遍历所有元素构成新的矩阵

### 代码

```python3
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        #元素数量不同不能构成矩阵
        num = len(nums) * len(nums[0])
        if num != r*c:
            return nums
        #统计所有元素
        nums_ = nums[0]
        for i in range(1, len(nums)):
            nums_ += nums[i]
        #遍历所有元素，按行构成新的矩阵
        ans = []
        for i in range(r):
            ans.append(nums_[i*c:(i+1)*c])
        return ans
        
```