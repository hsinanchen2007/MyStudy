```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, h = 0, len(nums) - 1
        while l < h:
            m = (l + h) // 2
            if nums[m] < nums[h]:
                h = m
            elif nums[m] == nums[h]:
                h -= 1
            else:
                l = m + 1
        return nums[l]
```
- 每次都需要判断 m 是否在未被旋转的部分上（右部），如果在，则向左搜索，否则向右搜索
- 当 nums[m] < nums[h] 时可以确定在右部，由于存在重复数字，当 m 指向的数字和 h 指向的相同时，可以直接收缩搜索范围(`h -= 1`），反正他们所代表的数字还有至少一个在搜索范围内