### 解题思路
1、处理特殊情况：长度为0返回“”，长度为1返回第一个字符串
2、计算strs中的字符串最小长度，strs中每个字符串的相同下标的字符均比较，相同则+，不同则返回已有相同前缀字符串

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        out_s = ""
        # 取字符串最小长度
        length = len(strs[0])
        for s in strs:
            if len(s) < length:
                length = len(s)
        for i in range(length):
            for j in range(len(strs)-1):
                if strs[j+1][i] != strs[j][i]:
                    return out_s
            out_s += strs[0][i]
        return out_s
```