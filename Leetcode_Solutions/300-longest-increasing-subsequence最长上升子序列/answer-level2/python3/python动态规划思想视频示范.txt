利用动态规划的思想，将数列从后向前按照level重新进行划分，起始值属于level0，当下一个值比level0的最大值小时，即提升至level1，继续比较，当前数只要比leveln的最大数小就可以继续与下一个level的最大数比较。
![最大升序子数列.mp4](b8a7a2ce-c149-4f38-9322-9a640b80be87)
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        s = []
        ans = 0
        for i in range(len(nums)):
            s.append([])
        for i in range(len(nums)-1,-1,-1):
            count = 0
            for j in range(ans):
                if nums[i] < max(s[j]):
                    count += 1
                else:
                    break
            s[count].append(nums[i])
            if count == ans:
                ans += 1
        return ans
```
