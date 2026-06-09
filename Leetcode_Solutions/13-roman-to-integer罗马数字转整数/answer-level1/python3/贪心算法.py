### 解题思路
从第一个字母开始遍历:
如果当前字母和下一个字母`在`字典中`s[i] + s[i + 1] in N`, 取N[s[i] + s[i + 1]]的值加给res, 然后 `i += 2`
如果当前字母和下一个字母`不在`字典中`s[i] + s[i + 1] not in N`, 取N[s[i]的值加给res, 然后 `i += 1`.


### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        N = {'M': 1000,'CM': 900,'D': 500, 'CD': 400, 'C': 100, 'XC': 90, 'L': 50, 'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1}
        i, res = 0, 0
        while i < len(s):
            if s[i] + s[i + 1] in N:
                res = res + N[s[i] + s[i + 1]]
                i += 2
            else:
                res = res + N[s[i]]
                i += 1
        return res
```