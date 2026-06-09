### 解题思路
由于列表长度在不断地变化，所以用while循环会很好思考和处理。
在由于前后是重复项而被删掉的时候，就不需要更新i的值，如果不是重复项则需要+1然后继续进行循环。
### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        while i < len(nums)-1:
            if nums[i] == nums[i+1]: 
                del nums[i]
            else:
                i += 1
        return len(nums)
```