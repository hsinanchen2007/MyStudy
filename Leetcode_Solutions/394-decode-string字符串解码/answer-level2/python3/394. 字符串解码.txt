### 解题思路
https://leetcode-cn.com/problems/decode-string/solution/decode-string-fu-zhu-zhan-fa-di-gui-fa-by-jyd/

### 代码

```python3
class Solution:
    def decodeString(self, s: str) -> str:
        multi = 0
        stack = []
        res = ''

        for i in s:
            if i.isdigit():
                multi = 10*multi + int(i)
            elif i.isalpha():
                res += i
            elif i == '[':
                stack.append([multi, res])
                res = ''
                multi = 0
            elif i == ']':
                last_multi, last_res = stack.pop()
                res = last_res + res*last_multi
        return res

```