### 解题思路
使用len函数判断该字符串长度，为零直接返回"",其次是运用内置函数max和min来调取该字符串中的最长和最短字符串，然后用for语句比较，记住此时的len语句调用的应该是min函数的字符串，不然的话会溢出，然后直接返回即可。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        else:
            str1 = max(strs)
            str2 = min(strs)
            n = 0
            for index in range(len(str2)):
                if str1[index] is str2[index]:
                    n += 1
                else:
                    break
            return str1[:n:1]
```