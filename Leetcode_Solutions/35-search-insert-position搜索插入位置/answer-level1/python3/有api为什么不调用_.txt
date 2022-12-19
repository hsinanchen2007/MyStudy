### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        import bisect
        try:
            return nums.index(target) 
        except:
            return bisect.bisect(nums,target)
```