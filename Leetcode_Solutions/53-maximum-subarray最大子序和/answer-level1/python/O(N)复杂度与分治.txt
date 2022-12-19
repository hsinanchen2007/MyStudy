三种方法：
方法一：
```python []
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        p = float('-inf')
        ans = p
        for s in nums:
            if p<0 and p<s:
                p = s
            else:
                p += s
            if ans<p:
                ans = p
        return ans
```
方法二：
```python []
class Solution(object):
    def maxSubArray(self, nums):
        ans = nums[0]
        s = 0
        for x in nums:
            s = max(s+x,x)
            if ans<s:
                ans = s
        return ans
```
方法三（分治）：
```python []
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        def MCS(nums,s,t):
            if s == t:
                return nums[s]
            m = s + (t-s)//2
            s1 = MCS(nums,s,m)
            s2 = MCS(nums,m+1,t)
            #merge left and right
            sl = nums[m]
            sa = sl
            sr = nums[m+1]
            sb = sr
            l = m-1
            r = m+2
            while l>=s or r<=t:
                if l>=s:
                    sl += nums[l]
                    l -= 1
                    if sa<sl:
                        sa = sl
                if r<=t:
                    sr += nums[r]
                    r += 1
                    if sb<sr:
                        sb = sr
            return max(s1,s2,sa+sb)
        return MCS(nums,0,len(nums)-1)
                    
```
