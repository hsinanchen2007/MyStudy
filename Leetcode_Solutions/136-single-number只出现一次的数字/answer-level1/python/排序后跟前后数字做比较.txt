### 解题思路
先将数组排序，若该数字跟排在它前面的数和后面的数均不相等，即返回该数字，再加上对数组首尾的判断即可

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        lens = len(nums)
        if lens == 1:
            return nums[0]
        nums.sort()
        # 如果第一个数字跟第二个数字不同，即为第一个数
        if nums[0] != nums[1]:
            return nums[0]
        # 如果最后一个数字跟倒数二个数字不同，即为最后一个数字
        if nums[-1] != nums[-2]:
            return nums[-1]  
        # 非首尾数字
        for index, num in enumerate(nums):
            if index > 0 and index < lens - 1:
                if num != nums[index-1] and num != nums[index+1]:
                    return num



```