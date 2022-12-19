### 解题思路
这只是暴力求解的答案
自己要注意的就是strs列表可能为空，直接使用min()函数的话会报错

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs: return "" #这里的列表可能为空
        a = min(strs, key = lambda str: len(str))
        for i in range(len(a)):
            for j in range(len(strs)):
                if a[i] != strs[j][i]:
                    return a[:i]
        return a
```