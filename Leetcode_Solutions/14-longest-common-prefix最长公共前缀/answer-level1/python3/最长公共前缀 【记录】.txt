### 解题思路
垂直扫描法

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common=""
        if len(strs)==0:
            return ""

        for i in range(len(strs[0])):
  
            char =strs[0][i]
        
            for item in strs[1:]:
                if (i>len(item)-1) or item[i]!=char:
                    return common
            common=common+char
        return common
```