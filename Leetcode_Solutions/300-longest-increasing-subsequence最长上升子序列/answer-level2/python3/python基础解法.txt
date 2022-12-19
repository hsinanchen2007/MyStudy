### 解题思路
1. 第一想法就是用动态规划最这题，动态规划的递归式dp[i] = max(dp[i], dp[j] + 1)，dp[1] = 1
2. 可以用二分查找来替换第二层的搜索，这样时间就会变成nlogn

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # if not nums:
        #     return 0
        # count_list = list()
        # for i in range(len(nums)):
        #     count_list.append(1)
        #     for j in range(i):
        #         if nums[i] > nums[j]:
        #             count_list[i] = max(count_list[i], count_list[j] + 1)
        # return max(count_list)
        nums_length = len(nums)
        if nums_length < 2:
            return nums_length
        
        tail = [nums[0]]
        for i in range(1, nums_length):
            if nums[i] > tail[-1]:
                tail.append(nums[i])
                continue
            
            left = 0
            right = len(tail) - 1
            while left < right:
                mid = (left + right) >> 1
                if tail[mid] < nums[i]:
                    left = mid + 1  
                else:
                    right = mid
            tail[left] = nums[i]
        return len(tail)


```