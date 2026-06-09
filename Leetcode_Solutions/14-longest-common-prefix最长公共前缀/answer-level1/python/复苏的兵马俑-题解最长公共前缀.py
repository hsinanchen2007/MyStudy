### 题解思路1（堆栈法）
LeetCode中提交执行结果-执行用时：44 ms，内存消耗：13.5 MB。

### 代码
```python
from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ''
        new_list = ['',strs[0]]
        for i in range(0,len(strs)):
            new_list[0] = ''
            new_list.append(strs[i])
            for j in range(min(len(new_list[1]),len(new_list[2]))):
                if new_list[1][j] == new_list[2][j]:
                    new_list[0] += new_list[1][j]
                else:
                    break
            new_list[1] = new_list[0]
            new_list.pop()
        return new_list[0]
```

### 测试代码
```python
print('“["flower","flow","flight"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["flower","flow","flight"])))
print('“["aca","cba"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["aca","cba"])))
print('“["a"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["a"])))
print('“["flower","flight","flow"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["flower","flight","flow"])))
print('“["dog","racecar","car"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["dog","racecar","car"])))
print('“[]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix([])))
print('“["acc","aaa","aaba"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["acc","aaa","aaba"])))
```
### 运行结果
```python
“["flower","flow","flight"]”中所有字符串的最长公共前缀为："fl"
“["aca","cba"]”中所有字符串的最长公共前缀为：""
“["a"]”中所有字符串的最长公共前缀为："a"
“["flower","flight","flow"]”中所有字符串的最长公共前缀为："fl"
“["dog","racecar","car"]”中所有字符串的最长公共前缀为：""
“[]”中所有字符串的最长公共前缀为：""
“["acc","aaa","aaba"]”中所有字符串的最长公共前缀为："a"
```

### 题解思路2（水平扫描法）

知识点：str.find()
a）描述：
原文：
S.find(sub[, start[, end]]) -> int
Return the lowest index in S where substring sub is found, such that sub is contained within S[start:end].  Optional arguments start and end are interpreted as in slice notation.
Return -1 on failure.

中文：
S.find(sub[, start[, end]]) -> int
返回S中找到子字符串sub的最低索引，该子字符串包含在S[start:end]中。可选参数的开始和结束被解释为切片符号。
失败返回-1。

诠释：
find() 方法检测字符串中是否包含子字符串 str ，如果指定 beg（开始） 和 end（结束） 范围，则检查是否包含在指定范围内，如果指定范围内如果包含指定索引值，返回的是索引值在字符串中的起始位置。如果不包含索引值，返回-1。

b）语法：
find()方法语法：str.find(str, beg=0, end=len(string))

c）参数：
str：指定检索的字符串；
beg：开始索引，默认为0；
end：结束索引，默认为字符串的长度。

d）返回值
如果包含子字符串返回开始的索引值，否则返回-1。

LeetCode中提交执行结果-执行用时：32 ms，内存消耗：13.6 MB。

### 代码
```python
from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ''
        s = strs[0]
        for i in range(1, len(strs)):
            while strs[i].find(s) != 0:
                s = s[:-1]
        return s
```

### 测试代码
```python
print('“["flower","flow","flight"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["flower","flow","flight"])))
print('“["aca","cba"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["aca","cba"])))
print('“["a"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["a"])))
print('“["flower","flight","flow"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["flower","flight","flow"])))
print('“["dog","racecar","car"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["dog","racecar","car"])))
print('“[]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix([])))
print('“["acc","aaa","aaba"]”中所有字符串的最长公共前缀为："{}"'.format(Solution().longestCommonPrefix(["acc","aaa","aaba"])))
```

### 运行结果
```python
“["flower","flow","flight"]”中所有字符串的最长公共前缀为："fl"
“["aca","cba"]”中所有字符串的最长公共前缀为：""
“["a"]”中所有字符串的最长公共前缀为："a"
“["flower","flight","flow"]”中所有字符串的最长公共前缀为："fl"
“["dog","racecar","car"]”中所有字符串的最长公共前缀为：""
“[]”中所有字符串的最长公共前缀为：""
“["acc","aaa","aaba"]”中所有字符串的最长公共前缀为："a"
```