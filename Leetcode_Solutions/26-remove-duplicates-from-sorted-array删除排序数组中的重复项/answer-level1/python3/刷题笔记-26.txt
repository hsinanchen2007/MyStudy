# 题目关键信息
输入列表为有序列表
输入列表可能为空
不需要关心超出返回数组长度的部分

# 使用set()去重再转为list
**思路**
1. 利用python中set()的去重功能，先将输入list转换为set，去除重复数字
2. 将set再转为list
3. 注意，上述转换过程中，输入列表的顺序会被打乱，需要重新排序

**实现代码**
```python []
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        nums[:] = list(set(nums))
        nums.sort()
        return len(nums)
```


# 指针
**思路**
设置两个指针。
一个指针作为被比较的元素，记录值（target）以及在数组中的索引，代码中使用的是nums[0]。
另一个指针用来遍历列表中的元素，从索引1开始。
遍历时，遇到与target值相同的元素跳过，遇到不同的就直接将该元素放置在target的后一位，同时target指针+1。
继续比较，直到遍历所有元素。
因为我们不需要关心超出新数组长度的部分，所以只在前面进行替换即可。

**实现代码**
```python []
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return length
        
        target = nums[0]
        i = 1
        j = 0
        while i < length:
            if target != nums[i]:
                nums[j+1] = nums[i]
                target = nums[i]
                j += 1
                i += 1
            else:
                i += 1
        return j+1
```
