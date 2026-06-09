### 解题思路
思想是，公共前缀可以表示为前两个的公共前缀，再与第三个比，再与第四个比。。。。。。
### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        res = strs[0] # 将第一个字符串作为比较的基础
        for i in range(1, len(strs)):
            while strs[i].find(res) != 0: # find()用来寻找相同的字符串，如果没有返回-1，如果有就返回开始索引。此处我们寻找的是前缀，所以开始索引必为0，当0就表示找到了便可以跳出循环
                res = res[:-1] # 这个语法表示丢掉最后一位，我喜欢用pop
        return res

```