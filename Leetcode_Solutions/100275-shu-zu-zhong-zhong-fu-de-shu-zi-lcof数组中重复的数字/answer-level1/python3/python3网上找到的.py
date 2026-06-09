### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        my_dir ={}
        length = len(nums)
        res = -1
        for i in nums:
            if i < 0 or i >= length:
                return -1
            if i in my_dir:
                res = i 
            else:
                my_dir[i] = i
        return res

```