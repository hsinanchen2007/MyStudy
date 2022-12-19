1. 哈希表
当开始用的直接去数组里找值，这种方法效率太低了。用set或dict是检索最快的
```
# exceed the time limit
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(0, len(nums) + 1):
            # 这种匹配是没有哈希表快的
            if i not in nums:
                return i
        return len(nums)

# 哈希表 dict和set 比 list查找速度要快很多
class Solution1(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # hash table
        dictionary = set(nums)
        for i in range(len(nums) + 1):
            if i not in dictionary:
                return i
        return len(nums)
```


2. 数学
return 加和 - sum(list) 这种方式是最快的
```
# 数学方法 该方法是最好的
class Solution3(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        return n * (n + 1) / 2 - sum(nums)
```


3. 位运算 异或方式 相同的元素异或后, 一定是0
```
"""
下标: 0,1,2
数字: 1,2,0

每一位累计异或
3^(0^1)^(1^2)^(2^0)
= (0^0)^(1^1)^(2^2)^3
= 3
"""
class Solution3(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        miss = len(nums)
        for index, data in enumerate(nums):
            miss = miss ^ index ^ data
        return miss
```
