### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        i ,j = 0,1
        common = ""
        if len(strs) == 0:
            return ""
        while j <= len(strs[0]):
            common = strs[0][i:j]
            for value in strs:
                if value[i:j] != common:
                    j -=1
                    break
            else:
                j += 1
                continue
            break
        return strs[0][i:j]

            
```