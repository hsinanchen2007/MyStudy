### 解题思路
思路是找前缀枚举，题意要求找最长，就从str1和str2中最短那一条的长度开始往下找str1的前缀，当然这个前缀的长度必定得能被str1和str2的长度除尽。找到前缀之后试着拼一下，如果能拼出str1和str2的话那么就返回，如果找到最后还是没有这样的字符串就返回一个空串。

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1, len2 = len(str1), len(str2)
        for i in range(min(len1, len2), 0, -1):
            if len1 % i == 0 and len2 % i == 0:
                if str1[:i] * (int(len1 / i)) == str1 and str1[:i] * (int(len2 / i)) == str2:
                    return str1[:i]
        return ""
```