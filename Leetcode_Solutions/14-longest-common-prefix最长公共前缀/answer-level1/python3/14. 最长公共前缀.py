### 解题思路
挑出字符串数组中的最短字符串，以其长度作为循环范围

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        length = len(strs)
        if length == 0:
            return ""
        elif length == 1:
            return strs[0]
        else:
            min_len = len(strs[0])
            for i in range(1,length):
                if len(strs[i])<min_len:
                    min_len = len(strs[i])
            common = ""
            for i in range(min_len):
                temp = strs[0][i]
                for j in range(length):
                    if temp != strs[j][i]:
                        return common
                common +=temp
            return common
```