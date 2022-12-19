### 解题思路
时间复杂度：O(n)
空间复杂度：O(1)，字符数有限，所以字典里的元素也是有限的。
关键：用一个字典记录字符最近一次出现的索引，用一个变量（start）记录当前子串开始的索引。

循环遍历字符，如果字符没有出现在从start起到当前位置的前一个位置的字符串里，更新字典里当前字符出现位置，反之，比较res和当前子串的长度（start到当前位置的前一个位置），根据字典更新start为当前字符出现的最近位置的后一个位置，更新字典里当前字符的最新位置。
### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s or len(s) < 2:
            return len(s)
        start, res = 0, 1
        dic = {s[0]: 0}
        for i in range(1, len(s)):
            if s[i] not in s[start: i]:
                dic[s[i]] = i
            else:
                res = max(res, len(s[start: i]))
                start = dic[s[i]] + 1
                dic[s[i]] = i
        return max(res, len(s[start:]))
```