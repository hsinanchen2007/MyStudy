```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k==1:return nums
        from collections import deque
        d,ans=deque(),[]
        for i in range(len(nums)):
            while len(d)>0 and nums[i]> nums[d[-1]]:
                d.pop()
            d.append(i)
            if i-d[0]==k:d.popleft()
            ans.append(nums[d[0]])
        return ans[k-1:]
```
这里用到了切片，不要那些，不满18岁的小朋友，你懂的。
if i-d[0]==k:d.popleft()
用来控制体重，，别吃太多了，吃多了，请赶快吐。

