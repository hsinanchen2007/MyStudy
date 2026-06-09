### 解题思路
使用 Python 內建功能

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target not in nums:
            return -1
        return nums.index(target)    
```