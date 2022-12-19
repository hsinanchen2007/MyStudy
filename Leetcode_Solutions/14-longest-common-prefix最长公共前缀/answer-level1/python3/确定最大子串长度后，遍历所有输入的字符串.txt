### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''

        if len(strs) == 1:
            return strs[0]

        search_size = min([len(s) for s in strs])

        for i in range(0, search_size+1):
            search_str = strs[0][0:i]
            for s in strs:
                if s[0:i] != search_str:
                    return strs[0][0:i-1]

        return strs[0][0:search_size]

```