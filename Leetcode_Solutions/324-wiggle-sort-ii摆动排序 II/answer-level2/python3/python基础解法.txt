### 解题思路
利用排序来解决，由于是严格的排序，所以排序的时候reverse让有重复的值隔的更远一些，然后穿插赋值

### 代码

```python3
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort(reverse=True)
        mid = len(nums) // 2
        nums[1::2], nums[0::2] = nums[:mid], nums[mid:]
```