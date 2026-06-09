### 解题思路
首先统计A中的独特的数字的个数，然后用回溯的方法：
选取一个数字num，如果num和之前选的数字加起来是一个数的平方，那么就减去num的个数，递归回溯剩下的数字。

### 代码

```python3
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        def backtrace(remain, cur_arr):
            if not remain:
                return 1
            ans = 0
            for num in list(remain):
                s = num if not cur_arr else num+cur_arr[-1]
                if not cur_arr or int(s**0.5)**2 == s:
                    remain[num] -= 1
                    if remain[num] == 0:
                        del remain[num]
                    ans += backtrace(remain, cur_arr+[num])
                    remain[num] += 1
            return ans
        return backtrace(collections.Counter(A), [])











```