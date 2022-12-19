### 解题思路
因为只可能存在一个众数，所以直接对数组进行排序，正序倒序无所谓，然后数组中间的那个值必然是那个众数。

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 对数组进行排序
        new_list = sorted(nums)
        # 取数组当中的那个值
        return new_list[len(nums)/2]
```