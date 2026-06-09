### 解题思路
python字典，哈希表
如果通过暴力破解法，列表中元素挨个遍历进行判断计算，代码较多，耗时较多
通过参考其他大神的解题思路，可以不用enumerate（）函数，通过用for循环，循环len（nums）次，进行判断，加入字典中。
### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for index, value in enumerate(nums):
            if target-value in dict:
                return [dict[target-nums[index]], index]
            else:
                dict[value] = index

```