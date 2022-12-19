时间 99.21% 空间100%
代码可能看上去比较麻烦，但思路很直觉。
其实就是考虑到最大值在当前窗口出现可能不止一次，以及当最大值离开窗口时，重新寻找之前次大值（目前的最大值）。
先统计第一个窗口中的最大值m以及其出现的次数cnt。将m加入结果列表res
每次滑动时，如果窗口头部进来的数比m大，则更新m为该数值，cnt=1.
否则，如果窗口尾部出去了一个m，则cnt -= 1，如果窗口头部新进来了一个m，则cnt += 1
如果此时cnt == 0，那么从当前窗口找出新的最大值并统计其出现次数。作为新的m与cnt。
将当前m加入到res，开始下一轮。
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == 0:   return []
        res = []
        n = len(nums)
        cnt = 1
        m = nums[0]
        for i in range(1, k):
            if nums[i] == m:
                cnt += 1
            elif nums[i] > m:
                m = nums[i]
                cnt = 1
        res.append(m)
        for i in range(1, n - k + 1):
            if nums[i + k - 1] > m:
                m = nums[i + k - 1]
                cnt = 1
                res.append(m)
                continue
            if nums[i - 1] == m:
                cnt -= 1
            if nums[i + k - 1] == m:
                cnt += 1
            if cnt == 0:
                m = max(nums[i : i + k])
                for num in nums[i : i + k]:
                    if num == m:
                        cnt += 1
            res.append(m)
        return res
```
