1. DP 跟爬楼梯一样的
[1,2,3,4,5]
是选择1,3还是1,4的问题 (因为你选择1,5 最后还是1,3,5最大)
每个子问题都是间隔1个还是2个的问题

跟爬楼梯问题是一样的, 是选择一步还是两步的问题。
L(n) = f(n) + max(f(n-1), f(n-2))

```
class NumArray(object):
  
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        # i - j 
        # _sum = L[0: i] + L[i: j + 1] + L[j + 1: len(nums)]
        # L[i: j + 1] = _sum -  L[0: i] - L[j + 1: len(nums)]
        # L[i: j + 1] = _sum - L[0: i] - (_sum - L[0:j+1])

        # L[i:j+1] = L[0:j+1] - L[0:i]

        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        self.nums = nums

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.nums[j+1] - self.nums[i]
```

2. 普通截取
```
class NumArray(object):
  
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return sum(self.nums[i:j+1])
```
