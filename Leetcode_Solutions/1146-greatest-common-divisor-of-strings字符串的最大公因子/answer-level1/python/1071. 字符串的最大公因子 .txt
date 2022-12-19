### 解题思路
首先判断字符串元素去重以后是否相等，如果这点都不能满足，那么就不会存在最大公因子
最大公因子的长度取决于较短的字符串
倒序处理，当且仅当选定的字符串长度既能被str1整除，又能被str2整除时才可以进行下一步判断

### 代码

```python
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        if set(str1) != set(str2):return ""
        l = min(len(str1),len(str2))
        for i in range(l,0,-1):
            if len(str1) % i == 0 and len(str2) % i == 0 :
                if str1[:i] * (len(str1)//i) == str1 and str1[:i] * (len(str2)//i) == str2:
                    return str1[:i]
        return ""
```