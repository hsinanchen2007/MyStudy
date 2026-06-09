### 解题思路
使用哈希表记录每个数字的出现次数即可。

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        my_dict = {}
        for num in nums:
            my_dict[num] = my_dict.get(num, 0) + 1
        for key, value in my_dict.items():
            if value > len(nums) // 2:
                return key
```