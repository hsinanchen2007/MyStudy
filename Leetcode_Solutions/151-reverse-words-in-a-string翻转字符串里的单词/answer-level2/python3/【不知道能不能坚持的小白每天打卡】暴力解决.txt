### 解题思路
直接按题意暴力解决。
主要就是把单词拿到，然后倒叙拼接。

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        stack = ['']
        # 把单词分开
        for c in s:
            if c is not ' ':
                stack[-1] += c
            else:
                stack.append('')
        # 由于有连续出现空格的可能，所以把多余的空格清理一遍
        while '' in stack:
            stack.remove('')
        res = ''
        # 把找到的单词倒叙拼接回去
        for i in range(len(stack)-1, -1, -1):
            res += stack[i] + ' '
        # 因为格式问题，会多一个空格，返回的时候剔除就行
        return res[:-1]
```