### 解题思路
把数组分为两部分，一部分是起始位置到遍历位置部分的数据，另一部分是从遍历位置到末尾的数据，如果当前遍历元素在第二部分，就表示该元素在列表中有多个重复的。删除该元素，直到第二部分不存在该元素为止，然后遍历下一个元素。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums):
        i =0
        while i <len(nums) :
            while nums[i] in nums[i+1:]:
                nums.remove(nums[i])
            else:
                i +=1
        return len(nums)


```