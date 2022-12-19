### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        # 解法一
        # dicts = {}
        # for num in nums:
        #     if str(num) in dicts:
        #         return num
        #     dicts[str(num)] = 1
        # return -1

        # 解法二
        # sets = set()
        # for num in nums:
        #     if num in sets:
        #         return num
        #     sets.add(num)
        # return -1

        # 解法三
        for i, value in enumerate(nums):
            while i != value:
                if value == nums[value]:
                    return value
                nums[i], nums[value] = nums[value], nums[i]
        return -1

```