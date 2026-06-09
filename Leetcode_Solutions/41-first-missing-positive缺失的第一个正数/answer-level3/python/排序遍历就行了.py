### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        i=1
        for num in nums:
            if num<i:
                pass
            elif num==i:
                i+=1
            else:
                return i
        return i
            
```