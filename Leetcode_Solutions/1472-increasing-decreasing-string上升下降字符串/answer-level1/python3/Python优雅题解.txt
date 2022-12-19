## 题目相关
- 原题链接：[1370. 上升下降字符串 - 力扣（LeetCode）](https://leetcode-cn.com/problems/increasing-decreasing-string/)
- 涉及知识：字符串、排序
- 题目难度：★
## 题目解读
由题意得，需要重复地从一个字符串（字符列表）中提取非重字符集合并排序直至源字符串中字符都被提取一次。
## Python相关
- 关于排序，我们可以直接调用Python内置的`list`的`sort`方法，通过设置`reverse`参数来控制是否降序。
- 关于字符集合提取，我们可以采用Python中`collections`内置库的`Counter`对象来操作
## 具体实现
```python
class Solution:
    def sortString(self, s: str) -> str:
        str_counter = collections.Counter(s)
        result = []
        flag = False
        while str_counter:
            keys = list(str_counter.keys())
            keys.sort(reverse=flag)
            flag = not flag
            result.append(''.join(keys))
            str_counter -= collections.Counter(keys)
        return ''.join(result)
```
