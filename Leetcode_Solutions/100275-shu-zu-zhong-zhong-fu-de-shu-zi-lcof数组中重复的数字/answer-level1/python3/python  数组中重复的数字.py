
# 方法一，采用内置排序后，进行遍历，这个样的好处，最大就是没有重复


```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        d = nums[0]
        for n in nums[1:]:
            if d==n:
                return n
            d = n
        return -1
```

# 方法二 采用字典进行计数
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        dic = dict()
        for n in nums:
            d = dic.get(n,0)
            if d>0:
                return n
            dic[n]= d+1
        return -1
```
