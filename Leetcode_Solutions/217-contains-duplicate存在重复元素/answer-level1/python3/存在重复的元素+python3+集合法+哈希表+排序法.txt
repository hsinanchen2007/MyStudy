### 解法1：集合法
判断原数组和该数组的长度相不相等，一行解决：
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len((set(nums))) != len(nums)
```
### 解法2：哈希表
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dic = {}
        for i in nums:
            if dic.get(i):
                return True
            dic[i] = 1
        return False
```
### 解法3：排序法
排序之后，相等元素必相邻：
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(len(nums)-1):
            if nums[i+1] == nums[i]:
                return True
        return False
```
