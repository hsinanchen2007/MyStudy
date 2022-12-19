### 解题思路
L数组: 左侧乘积
R数组: 右侧乘积
output[i] = L[i] * R[i]

### 代码

```python3
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        L = [0] * length # 左侧乘积
        R = [0] * length # 右侧乘积
        L[0] = 1
        for i in range(1, length):
            L[i] = L[i - 1] * nums[i - 1]
        R[length - 1] = 1
        for j in range(length-2, -1, -1):
            R[j] = R[j + 1] * nums[j + 1]
        
        output = [0] * length
        for k in range(length):
            output[k] = L[k] * R[k]
        return output
```