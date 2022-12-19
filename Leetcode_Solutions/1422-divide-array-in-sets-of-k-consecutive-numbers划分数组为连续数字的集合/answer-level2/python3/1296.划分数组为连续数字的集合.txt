### 解题思路
我自己写的超时了，看到评论里@typingMonkey用字典的最大数倒着比较的思想，觉得很赞
另外字典防止keyerror可以用collections.defaultdict(int)。学到了


### 代码

```python3
# 超时
# class Solution:
#     def isPossibleDivide(self, nums: List[int], k: int) -> bool:
#         if len(nums)%k != 0:
#             return False
#         else:

#             nums.sort()
#             while(len(nums)):
#                 for i in range(1,k):
#                     if nums[0]+i in nums:
#                         nums.remove(nums[0]+i)
#                     else:
#                         return False
                
#                 nums.pop(0)
                
#             return True

class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k != 0:
            return False
        else:
            d = collections.defaultdict(int)
            for i in sorted(nums, reverse=True):
                d[i] += 1
            while d:
                s, n = d.popitem()
                for i in range(s + 1, s + k):
                    if d[i] < n:
                        return False
                    elif d[i] == n:
                        del d[i]
                    else:
                        d[i] -= n
            return True


```