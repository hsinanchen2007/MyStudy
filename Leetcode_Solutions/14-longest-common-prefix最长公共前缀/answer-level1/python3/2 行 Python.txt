## 解析
```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        r = [len(set(c)) == 1 for c in zip(*strs)] + [0]
        return strs[0][:r.index(0)] if strs else ''
```
- 利用好 zip 和 set
- 【第一行】每次都取各个字符串的同一列字符，放进 set，set 中不会储存重复元素，所以长度为1代表各个字符都是相同的，此时 `==` 会让它变成 True
- 【第二行】index 搜索第一个 0 的位置，0 与 False 在值上是等价的，相当于搜索第一个 False 的位置也就是公共前缀的长度
## 细节补充
- zip(*str) 将 str 中所有字符串并列到迭代器中，逐次并列返回 str 中所有字符串的第 1、2、3、…… 个字符
- 第一行代码末尾添加了一个 `[0]` 是为了防止 index 函数搜索不到 0 时报错
