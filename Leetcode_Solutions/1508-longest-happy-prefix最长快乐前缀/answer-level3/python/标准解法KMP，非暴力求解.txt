### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPrefix(self, s: str) -> str:
        # ans  = ""
        # for i in range(len(s)):
        #     # print(s[:i], s[len(s)-i:])
        #     if s[:i] == s[len(s)-i:]:
        #         ans = s[:i]
        # return ans

        if not s:
            return None
        def getNextArr(str_):
            if len(str_) == 1:
                return [-1]
            next_arr = [0] * (len(str_) + 1)
            next_arr[0],next_arr[1] = -1,0
            pos,cn = 2, 0
            while pos < len(next_arr):
                if str_[pos-1] == str_[cn]:
                    next_arr[pos] = cn + 1
                    pos,cn = pos + 1, cn + 1
                elif cn > 0:
                    cn = next_arr[cn]
                else:
                    next_arr[pos] = 0
                    pos += 1
            return next_arr
        next_arr = getNextArr(list(s))
        return s[:next_arr[-1]]
```