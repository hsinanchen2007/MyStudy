先把列表排序，在与原来的列表进行比较，两次循环搞定
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        nums1 = sorted(nums)
        if nums == nums1:
            return 0
        else:
            a = 0
            b = len(nums)
            for i in range(len(nums)):
                if nums[i] == nums1[i]:
                    a += 1
                else:
                    break
            for j in range(len(nums)):
                if nums[-(j+1)] == nums1[-(j+1)]:
                    b -= 1
                else:
                    break
            return b - a
```
引用一位题解区老哥的解法，为什么思路都一样了，还是写不出这么优美的代码＞︿＜
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        diff = [i for i, (a, b) in enumerate(zip(nums, sorted(nums))) if a != b]
        return len(diff) and max(diff) - min(diff) + 1
```
真的佩服老哥对python的掌握程度


