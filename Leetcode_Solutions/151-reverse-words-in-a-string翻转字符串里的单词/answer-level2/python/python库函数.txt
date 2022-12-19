### 解题思路
利用 s.split() 实现字符串翻转。

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        str_list = s.split()[::-1]
        ss = ''

        for i in str_list:
            ss += i
            ss += ' '
        ss = ss[:-1]

        return ss

```