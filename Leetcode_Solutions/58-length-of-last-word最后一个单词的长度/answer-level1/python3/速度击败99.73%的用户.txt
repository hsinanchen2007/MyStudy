### 解题思路
string.isalpha()
#如果 string 至少有一个字符并且所有字符都是字母则返回 True,否则返回 False
string.rstrip()
#删除 string 字符串末尾的空格

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        if s.isalpha():
            return len(s)
        elif s != '':
            return len(s) - s.rfind(' ') - 1
        else:
            return 0
```