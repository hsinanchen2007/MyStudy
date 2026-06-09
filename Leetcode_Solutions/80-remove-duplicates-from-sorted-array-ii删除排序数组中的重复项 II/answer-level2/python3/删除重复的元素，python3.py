### 解题思路
遍历过程中，判断当前元素的值与上一元素的值是否相等
如果不相等就继续遍历
否则判断这个值连续出现的次数
如果次数大于2就删除当前值

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return
        pre = nums[0]
        i = 1
        times = 1
        while i < len(nums):
            if nums[i] != pre:
                pre = nums[i]
                i += 1
                times = 1
                continue
            else:
                times += 1
                if times > 2:
                    del nums[i]
                else:
                    i += 1

```