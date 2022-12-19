
这是需要连续的最大子序和，如果全是正数，那么遍历累加就是最大值，那如果中间有负数呢，我是加还是不加
比如[2,3,-2,5,2]
我遍历累加2，累加3，累加结果保存到tmp，然后遇到了-2，我加还是不加，
那么就分为两部分，如果我加了这个数，那么结果为tmp+i，如果不加，即为我从这里断开，开始新的一个开始，那么数值为i
那么我就要比较tmp+i和i的大小，如果累加更大，我累加下去，如果不累加就已经比累加更大了，那我肯定选新开始，当前结果为i
如[-8,5]:tmp最开始为-8，遇到5的时候，发现我直接从5开始比-8累加5更大，那么我肯定选择从5开始，而不是累加

并且在每一次的遍历中，我都要保存tmp的临时结果，用更大的值来刷新它

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        if not nums:
            return None
        
        res = nums[0]
        tmp = nums[0]
        
        for i in nums[1:]:
            tmp = max(tmp+i, i)
            res = max(tmp, res)
        
        return res
```

**时间复杂度为O(n)，空间复杂度为O(1)**

![image.png](https://pic.leetcode-cn.com/fb9ef91c5c2bfaed313b8148a2732d3804efbb226d2da482b342e28ac3a08546-image.png)
