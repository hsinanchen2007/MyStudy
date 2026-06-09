先想出了递归解， 很简单
代码如下
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums == []: return 0
        if len(nums) < 3: return max(nums)
        return max(nums[0] + self.rob(nums[2:]), nums[1] + self.rob(nums[3:]))
```
然后超时了/滑稽

开始想dp解（这是我写的时间最长的题（没写出来的不算。。。
失败的想法我也不知道该怎么说， 所以略过
最后重新看一开始代码
可以看出有重复计算的部分， 而且很多。。。
所以我想到了备忘录法， 但是没写， 继续想
然后我突然想到了， 知道了到前面一个、 两个、 三个的就可以推出这个点值， 所以有了下面代码
1. 如果nums长度小于3, 直接求最大值就行了
2. 如果大于等于三， 可以从第三点开始递推
具体思路看代码吧。。。

```
    class Solution:
        def rob(self, nums: List[int]) -> int:
            if len(nums) < 3:
                return max(nums, default=0)
            def helper(nums, start, dp0, dp1, dp2):
                if start == len(nums):
                    return max(dp0, dp1)
                return helper(nums, start+1, max(dp1, dp2)+nums[start], dp0, dp1)
            return helper(nums, 3, nums[2]+nums[0], nums[1], nums[0])
```