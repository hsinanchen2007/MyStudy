### 解题思路
此处撰写解题思路
不断更新最远指针
### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if nums == []:
            return False
        
        far = 0
        for i in range(len(nums)):
            if nums[i] == 0 and i != len(nums) - 1:
                if far <= i:
                    return False
            
            else:
                count = 0
                far = max(i + nums[i],far)
        
        return True
```