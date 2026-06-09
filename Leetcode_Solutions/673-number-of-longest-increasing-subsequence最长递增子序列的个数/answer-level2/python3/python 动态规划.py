### 解题思路
lengths[i]记录下标为i的最长递增序列的长度,counts[i]记录下表为i的最长长度的数量
双循环，当nums[i]>nums[j]的时候，判断lengths[j]是否大于等于length[i],如果是就更新lengths[i]为length[j]+1
counts[i]为counts[j]+1。如果lengths[j]==length[i-1],那么相当于在原有count[i]上有增加了counts[j]
### 代码

```python3
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n=len(nums)
        if n<=1:
            return n
        lengths=[1]*n
        counts=[1]*n
        for i in range(n):
            for j in range(i):
                if nums[i]>nums[j]:
                    if lengths[j]>=lengths[i]:
                        lengths[i]=lengths[j]+1
                        counts[i]=counts[j]
                    elif lengths[j]==lengths[i]-1:
                        counts[i]+=counts[j]
        longest=max(lengths)
        return sum(c for i,c in enumerate(counts) if lengths[i]==longest)

```