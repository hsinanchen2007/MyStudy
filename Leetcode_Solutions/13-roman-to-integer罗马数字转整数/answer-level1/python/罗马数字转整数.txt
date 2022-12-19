### 解题思路
可以遍历所有罗马字母相加，如果遇到IV或IX，相加的和减去2即可，以此类推。

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dict1 = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        j = 0
        for i in s:
            j += dict1.get(i)
        if 'IV' in s or 'IX' in s:
            j -= 2
        if 'XL' in s or 'XC' in s:
            j -= 20
        if 'CD' in s or 'CM' in s:
            j -= 200
        return j
```