### 解题思路
先写测试用例：
[2,3,4,5] 9 -> [2,3]
[3,3] 6 -> [0,1]
由于一个元素只能访问一遍，则不能重复遍历，只能有一个for，当需要考虑其他的在列表中查找元素的方法，例如find,count等。
而index只能返回第一个元素索引，所谓我们用dict来获取获得所有元素的索引。
### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in nums:
            y = target - i
            if nums.count(y) ==1 and nums.index(i) != nums.index(y):
                return [nums.index(i), nums.index(y)]
            elif nums.count(y) >1:
                nums_index = range(len(nums))
                dic_nums_index = dict(zip(nums_index, nums))
                index_list = []
                for key, value in dic_nums_index.items():
                    if value == y:
                        index_list.append(key)
                return index_list
            else:
                next
```