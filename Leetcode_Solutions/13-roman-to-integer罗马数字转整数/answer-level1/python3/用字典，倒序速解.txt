### 解题思路
1. 用 dict结构 存好转换表
2. 将字符串 **s** 倒序，`s.reversed` or `s[::-1]`
3. 依次判断，若当前值(cur) <= tmp, `ans += cur`；否则 `ans -= cur`

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        '''if not s:
            return 0'''
        
        shift = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }

        ans = tmp = 0
        for ch in s[::-1]:
            cur = shift[ch]
            ans = (ans + cur) if tmp <= cur else (ans - cur)
            tmp = cur
        return ans
```