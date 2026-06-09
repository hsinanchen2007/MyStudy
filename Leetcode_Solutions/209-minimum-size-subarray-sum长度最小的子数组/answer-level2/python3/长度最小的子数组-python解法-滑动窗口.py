# 滑动窗口-python解法
要求是连续子数组，所以我们必须定义 i，j两个指针，i 向前遍历，j 向后遍历，相当与一个滑块，这样所有的子数组都会在 [i...j] 中出现，如果 nums[i..j] 的和小于目标值 s，那么j向后移一位，再次比较，直到大于目标值 s 之后，i 向前移动一位，缩小数组的长度。遍历到i到数组的最末端，就算结束了，如果不存在符合条件的就返回 0。

![微信截图_20191111215043.png](https://pic.leetcode-cn.com/1fd7dad4a51466e21823431fc804980a1f2b5d7e131656c2a32f3bed1c062ad8-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191111215043.png)

python解法：

```
class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)
        if (n < 1 or sum(nums) < s):
            return 0
        
        # 维护一个滑动窗口nums[i,j], nums[i...j] < s
        i = 0
        j = -1
        total = 0
        res = n + 1
        while i <= n-1:
            if (j + 1 < n) and total < s:
                j += 1
                total += nums[j]
            else:
                total -= nums[i]
                i += 1
            
            if (total >= s):
                res = min(res, j-i+1)
        if res == n+1:
            return 0
        return res
```

![白色背景关注.jpg](https://pic.leetcode-cn.com/47d1b5430e869ed420bb0c6e8a90250773528ccf1bf6d4d43aef80dd326eeef9-%E7%99%BD%E8%89%B2%E8%83%8C%E6%99%AF%E5%85%B3%E6%B3%A8.jpg)
