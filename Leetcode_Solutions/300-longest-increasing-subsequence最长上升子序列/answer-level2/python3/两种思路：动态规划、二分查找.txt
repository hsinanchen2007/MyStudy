解法一：动态规划
思路：遍历数组的每个元素，如果当前元素大于在他前面的任何一个元素，状态转移方程为 if n-1 < n, f(n)=f(n-1)+1
时间复杂度：O(n*n)
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 注意处理异常输入
        if nums == []:
            return 0
        # 状态转移方程为 if n-1 < n, f(n) = f(n-1) + 1
        n = [1] * len(nums)
        # 遍历每个元素，从1开始
        for i in range(1, len(nums)):
            # 分别与在它之前的元素相比较
            for j in range(i):
                # if n-1 < n, f(n) = f(n-1) + 1
                if nums[j] < nums[i]:
                    n[i] = max(n[i], n[j] + 1)
        return max(n)
```

解法二：贪心算法 + 二分查找
思路：如果后续的元素大于数组末尾的元素，则接在末尾；否则找到第一个大于等于元素的值，然后替换
时间复杂度：O(nlog⁡n)
```
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        tail = [nums[0]]
        for i in range(1, len(nums)):
            # 如果后续的元素大于数组末尾的元素，则接在末尾
            if nums[i] > tail[-1]:
                tail.append(nums[i])
                continue
            # 找到第一个大于等于元素的值，然后替换
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
