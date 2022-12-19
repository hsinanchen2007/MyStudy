### 解题思路
移动窗口，当前子串的和等于前一状态的子串的和加上/减去当前移动的值。

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums):
        i,j = 0,0
        res = s
        # 数组为空，则返回0
        if sum(nums) < s: return 0
        ans = nums[0]
        while j < len(nums):
            if ans < s:
                j += 1
                if j != len(nums):
                    # 下一时刻的子串和
                    ans += nums[j]
                                             
            elif ans >= s:
                res = min(res, j-i+1)
                ans -= nums[i]
                i += 1

        return res 
```