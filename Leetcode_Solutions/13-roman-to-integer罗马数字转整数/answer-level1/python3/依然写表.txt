### 解题思路

和题 12 数字转罗马一样的思路。写出表来，从大到小依次减去。要注意 CM, CD, XC, XL, IX, IV 是两位，还有数组边界的问题。

![image.png](https://pic.leetcode-cn.com/2d2744f65c6fb11002b44f189a4c33a6815070885cdb0d9b932f96f70ce81a18-image.png)

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        digits = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        result = 0
        for i in range(13):
            if len(romans[i]) == 1:
                while len(s) > 0 and s[0] == romans[i]:
                    result = result + digits[i]
                    s = s[1:]
            elif len(romans[i]) == 2:
                while len(s) > 1 and s[0:2] == romans[i]:
                    result = result + digits[i]
                    s = s[2:]
        return result
```