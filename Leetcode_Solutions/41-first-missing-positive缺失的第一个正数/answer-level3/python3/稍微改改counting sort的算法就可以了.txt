![1577523478(1).png](https://pic.leetcode-cn.com/80f89f65a49f0e60532276d33860a3ab83c018daf709351d59f9e301a9e3b0e0-1577523478\(1\).png)
刚才基础看那个算法导论，听了几节网易公开课里面老师讲的东西。碰到这个题，我首先就想到刚学习过的counting sort算法。因为它是我听到的第一个线性时间的算法。所以用这个思路来做的。基本代码如下：
```
class Solution:
    def firstMissingPositive(self, nums) -> int:
        k = 0
        for x in nums:
            if x > k:
                k = x
        c = []
        n = len(nums)
        k = min(k,n)
        for i in range(k+1):
            c.append(0)
        for i in range(n):
            if nums[i] < 0 or nums[i] > k:
                continue
            else:
                c[nums[i]] += 1
        m = k + 1
        for i in range(0,k):
            j = k - i
            if c[j] == 0:
                m = j
        return m
```
可是呢，其实我觉得这个空间的消耗并不是常数啊...我觉得应该是O(k+n)...