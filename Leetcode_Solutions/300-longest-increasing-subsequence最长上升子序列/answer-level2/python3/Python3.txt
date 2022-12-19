### 解题思路
1. 使用字典存储每个数字的最长上升序列.
2. 使用tail数组, 其中tail[i]保存所以长度为i的上升子序列中其末尾元素的最小值

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # res = 0
        # d = {i:1 for i in range(len(nums))}
        # for i in range(len(nums)-1, -1, -1):
        #     tmp = 0
        #     for j in range(i+1, len(nums)):
        #         if nums[j] > nums[i]:
        #             tmp = max(tmp, d[j])
        #     d[i] += tmp
        #     res = max(res, d[i])
        # return res  
        
        # 找到第一个小于等于k的数的位置
        def binarySearch(nums, k):
            l, r = 0, len(nums)-1
            while l <= r:
                mid = (l + r) // 2
                if nums[mid] == k:
                    r = mid - 1
                elif nums[mid] < k:
                    l = mid + 1
                elif nums[mid] > k:
                    r = mid - 1
            return r + 1

        if len(nums) <= 1:
            return len(nums)
        tail = [nums[0]]
        for i in nums:
            # 大于末尾元素, 直接插入
            if i > tail[-1]:
                tail.append(i)
            # 找到第一个大于等于nums的位置
            else:
                index = binarySearch(tail, i)
                tail[index] = i
        return len(tail)
```