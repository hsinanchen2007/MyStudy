### 解题思路
遍历的时候优先看有没有2个字符能转换整数的，没有才取一个字符转换整数。

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        trans_map = {
            'I': 1,
            'IV': 4,
            'V': 5,
            'IX': 9,
            'X': 10,
            'XL': 40,
            'L': 50,
            'XC': 90,
            'C': 100,
            'CD': 400,
            'D': 500,
            'CM': 900,
            'M': 1000
        }
        max_len = len(s)
        b = 0
        ans = 0
        while b < max_len:
            two_chars = s[b:b+2]
            one_chars = s[b:b+1]
            if two_chars in trans_map:
                ans += trans_map[two_chars]
                b += 2
            else:
                ans += trans_map[one_chars]
                b += 1

        return ans

```