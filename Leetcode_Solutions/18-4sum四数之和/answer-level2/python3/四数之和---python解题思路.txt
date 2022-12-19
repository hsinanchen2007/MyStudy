首先这种题目暴力破解肯定是不行的，可定会遇到超时
想到了之前的三数之和问题,在三数之和的问题
最简单的就是在找三数之和的情况下加上一个遍历，再构造出招三个数的情况
算法：双指针

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = set()
        nums = sorted(nums)
        for i,each in enumerate(nums):
            self.findthree(nums[i+1:], target - each, result, each)
        return result

    def findthree(self, nums, target, result, four):
        for i,each in enumerate(nums):
            left = i + 1
            right =  len(nums) - 1
            new_target = target - each
            while left < right:
                if nums[left] + nums[right] == new_target:
                    result.add((four, nums[i], nums[left], nums[right]))
                    left += 1
                if nums[left] + nums[right] < new_target:
                    left += 1
                if nums[left] + nums[right] > new_target:
                    right -= 1
```

运行结果

```
执行用时 :1700 ms, 在所有 python3 提交中击败了17.96% 的用户
内存消耗 :13.7 MB, 在所有 python3 提交中击败了11.30%的用户

执行用时 :1472 ms, 在所有 python3 提交中击败了26.09% 的用户
内存消耗 :13.7 MB, 在所有 python3 提交中击败了11.30%的用户

执行用时 :1392 ms, 在所有 python3 提交中击败了28.95% 的用户
内存消耗 :13.8 MB, 在所有 python3 提交中击败了11.17%的用户
```

感觉速度和之前的3数之和还是差不多的(*^▽^*)
后面再优化
欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)