### 思路一：循环遍历
循环遍历数组，用common记录当前的公共前缀，起始为第一个字符串，每次循环先比较当前字符串的长度和common的长度，将common设置为短的那一个，然后遍历common和当前字符串比较，有两种方法比较：从前往后（一个字符一个字符比），从后往前（切片比较字符串）。循环过程中，一旦common为空就返回。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        common = strs[0]
        for i in range(1, len(strs)):
            s = strs[i]
            if len(s) < len(common):
                common, s = s, common
            l = len(common)
            for i in range(len(common) - 1, -1, -1):
                if s[:i + 1] == common[:i + 1]:
                    common = common[:i + 1]
                    break
                l -= 1
            if not l:
                return ""
            common = common[:l]
        return common
```

### 思路二：排序
利用内置min()，max()找出字符串数组中最大和最小的字符串，直接比较两个字符串的公共前缀，该前缀一定是所有字符串的最大公共前缀。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        s, l = min(strs), max(strs)

        for i in range(len(s) - 1, -1, -1):
            if s[: i + 1] == l[: i + 1]:
                return s[: i + 1]
        return ""
```

### 思路三：垂直比较
利用zip和set垂直比较每个字符串的相同位置的字符。zip的长度等于最短字符串的长度。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        res = ""
        for  chars in zip(*strs):
            if len(set(chars)) == 1:
                res += chars[0]
            else:
                return res
        return res
```