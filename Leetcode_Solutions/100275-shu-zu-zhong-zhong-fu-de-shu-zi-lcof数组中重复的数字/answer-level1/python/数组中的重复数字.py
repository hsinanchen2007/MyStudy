# 哈希表
# 解题思路
遍历数组，将数组的值存入新建的空字典，在遍历的时候，若重复出现相同的键，返回该值即可
缺点：多用了空间，新建了字典
时间复杂度：o(n)  
# 代码
```
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 哈希表
        d = {}
        for num in nums:
            if num not in d:
                d[num] = 0
            else:
                # 只要里面存在这个key,就说明这个数字出现了2次，直接返回就行
                return num
```
# 暴力解法
# 解题思路
从第一个值开始向后比较，是否有相同的数字，有则直接返回
缺点：时间复杂点太高，超时，o(n^2)
# 代码
```
def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 暴力解法
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                if nums[i]==nums[j]:
                    return nums[i]
```
# 原地置换法
```
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                nums[nums[i]] , nums[i] = nums[i] , nums[nums[i]]
        
        return None
```

