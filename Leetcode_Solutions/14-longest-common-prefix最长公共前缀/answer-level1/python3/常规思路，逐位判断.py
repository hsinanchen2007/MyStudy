### 解题思路
常规思路

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ''
        i = 0
        length = len(strs)
        search = length > 0
        while search:
            temp = ''
            for j in range(length):
                if i >= len(strs[j]):
                    search = False
                    break
                if temp == '':
                    temp = strs[j][i]
                elif temp != strs[j][i]:
                    search = False
                    break
            if search:
                i = i + 1
                ans = ans + temp
        return ans
```