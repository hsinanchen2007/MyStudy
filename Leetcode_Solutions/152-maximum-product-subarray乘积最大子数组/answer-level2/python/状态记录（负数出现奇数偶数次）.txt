类似 [5337. 每个元音包含偶数次的最长子字符串](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)
计负数出现奇数次状态为1，出现偶数次为0，最大乘积就是两次相同状态之间的元素之积

```
class Solution(object):
    def maxProduct(self, nums):
        def reset():
            return 0, {0: 1}, 1
        state, count, res = reset()
        ans = nums[0] if 0 not in nums else 0
        for i, n in enumerate(nums):
            res *= n
            if n < 0:
                state = ~state
            elif n == 0:
                state, count, res = reset()
                continue
            if state not in count:
                count[state] = res
            else:
                ans = max(ans, res / count[state])
        return ans
```
