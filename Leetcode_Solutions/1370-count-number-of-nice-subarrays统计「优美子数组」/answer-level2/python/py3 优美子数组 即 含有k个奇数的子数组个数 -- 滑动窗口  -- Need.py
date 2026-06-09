### 解题思路
1. 一闪念的滑动窗口，但是没有相同，也就错过了，或者说还没有理解[滑动窗口的真谛 不看看此人的代码](https://leetcode-cn.com/problems/count-number-of-nice-subarrays/solution/1248-by-ikaruga/) 
2. 采用**hash的方式 + 滑动窗口**，很巧妙的
3. 【数组内乘积小于 k 的连续的子数组的个数 】也是滑动窗口的例子，**可以一起总结下规律，似乎也可以采用hash（一个） + 滑动窗口**。

### 代码

```python3
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        '''
        l = 0
        r = 0
        nsize = len(nums)
        if nsize < 1 or nsize < k:
            return 0
        
        cnt = 0
        ans = 0
        cs = 1
        while r < nsize:
            while r < nsize and cnt < k:
                if nums[r] % 2 == 1:
                    cnt += 1
                r += 1
                if cnt == k:
                    r -= 1
                    while r < nsize and  nums[r] % 2 == 0:
                        cs += 1
                        r += 1
                
            if cnt < k: # [err1] < [err2] r >= nsize
                break
            while nums[l] % 2 == 0:
                ans += cs
                l += 1
            l += 1 ## move one odd
            cnt -= 1
            ans += cs

        return ans
        '''
        res, tmp, dic = 0, 0, {0: 1}
        for num in nums:
            if num & 1:
                tmp += 1
                dic[tmp] = 1
            else:
                dic[tmp] += 1
            res += dic.get(tmp-k, 0)
        return res

```