### 解题思路
这题中文要好，就是没看中文想多了

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = ""
        for i in zip(*strs):
            if len(set(i)) == 1:
                s += i[0]
            else:
                break           
        return s
```