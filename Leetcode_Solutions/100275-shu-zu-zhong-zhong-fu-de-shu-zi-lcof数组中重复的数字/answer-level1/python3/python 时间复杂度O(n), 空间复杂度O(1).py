### 解题思路
思想就是对号入座，因为题目中数组元素的范围在0～n-1 中，如果没有重复的元素，则nums[i]==i，即应该对号入座
如果nums[i]==i ,则扫描下一元素
如果nums[i]！=i ,比较当前元素nums[i]与nums[num[i]],如果相等，即找出重复元素;如果不相等，即交换，将nums[i]放到对应的位置，即nums[nums[i]]
重复操作，即可找到重复元素

### 代码

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            if nums[i]!=i:
                if nums[nums[i]]==nums[i]:
                    return nums[i]
                else:
                    nums[nums[i]],nums[i]=nums[i],nums[nums[i]]
    


```