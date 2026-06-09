### 解题思路
概括起来：对每一个字符进行判断，字符只要比右边的值小，那就减掉；如果比右边大，那就加上去。

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        a = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        ans = 0
        for i in range(0, len(s)):
            if (i < len(s)-1) and (a[s[i]] < a[s[i+1]]):
                ans -= a[s[i]]
            else:
                ans += a[s[i]]
        return ans

```