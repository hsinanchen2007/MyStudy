### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums:
            return 0
        else:
            flag = 0
            for num in nums:
                if(num>=target):
                    break
                else:
                    flag +=1
        return flag
                  
```