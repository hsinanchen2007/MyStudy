### 解题思路
执行用时 :48 ms
内存消耗 :12.7 MB

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        num = 0
        dict1 = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
        dict2 = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        for i in dict1:
            if i in s:
                num = num + dict1[i]
                s = s.replace(i, '', 1)
        for i in dict2:
            n = s.count(i)
            num = num + n*dict2[i]
        return num
```