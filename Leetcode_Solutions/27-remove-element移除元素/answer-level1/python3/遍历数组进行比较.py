### 解题思路
此处撰写解题思路
这里直接遍历数组和val比较，要注意，便利的时候要直接便利到nums[0]
### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if not nums:
            return False
        for i in range(len(nums)-1,-1,-1):
            if nums[i]==val:
                nums.pop(i)
                i-=1
        return len(nums)
```