### 解题思路
因为题目中给的多数元素数量大于整个数组元素的一半，所以直接用Python自带的排序函数然后取中间的元素就可以了，两行解决

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return nums[len(nums)//2]

```