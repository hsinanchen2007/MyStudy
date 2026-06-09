主要思想存储不同长度的上升子序列中末尾数的最小值，找到一个比新来的数字小的最大的数进行更新即可，技巧：二分：mid处和left处必须有一个+1且只能有一个+1否则二分出边界,即l+r+1 l=mid 或者l+r l=mid+1,哨兵：在q[0]处加入哨兵，首先保证数组有序（哨兵非常小），其次哨兵可以保证每个数一定能在二分数组中找到比他小的最大值，而恰好是哨兵的情况就是单独以他为序列的子序列
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        L = [-2e5 for _ in range(len(nums) + 10)]
        le = 0
        for num in nums:
            l = 0
            r = le
            while l < r:
                mid = l + r + 1 >>1
                if L[mid] < num:
                    l = mid
                else:
                    r = mid - 1
            le = max(le, l + 1)
            L[l + 1] = num
        return le
```
