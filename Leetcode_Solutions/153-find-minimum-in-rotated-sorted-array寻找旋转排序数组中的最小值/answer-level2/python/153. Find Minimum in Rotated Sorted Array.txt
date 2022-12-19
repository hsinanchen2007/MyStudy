1. 暴力
2. 二分法
3. 排序查找nums[0]
4. 求数组中最小的 min(nums)

1.
```
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        
        for i in range(1, len(nums)):
          if (nums[i-1] > nums[i]):
              return nums[i]
        return nums[0]
print Solution().findMin([3,4,5,1,2])
```

2. 双指针
```
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        _len = len(nums)
        i, j = 0, _len - 1
        if _len == 1:
            return nums[0]

        while(j > i):
            print i, j
            if nums[i] < nums[i + 1]:
                i += 1
            else:
                return nums[i + 1]

            if nums[j] > nums[j - 1]:
                j -= 1
            else:
                return nums[j]
```


3. return sorted(nums)[0]
4. return min(nums)