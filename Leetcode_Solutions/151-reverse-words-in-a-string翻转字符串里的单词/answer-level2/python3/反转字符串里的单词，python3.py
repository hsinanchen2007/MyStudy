### 解题思路
先用split()分割字符串
然后逆序遍历分割好的字符串并累加，每两个元素之间加一个空格

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        res = ''
        for i in s.split(' ')[::-1]:
            if i == '': continue
            res += i + ' '
        return res[:-1]
```