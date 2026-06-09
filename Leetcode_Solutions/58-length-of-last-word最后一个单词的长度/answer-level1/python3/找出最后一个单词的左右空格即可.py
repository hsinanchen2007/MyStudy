### 解题思路
找出最后一个单词的左右空格即可

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        last = len(s) - 1
        while last >= 0:
            if s[last] != " ":
                break
            last -= 1
        i = 0
        while last >= 0:
            if s[last] == " ":
                break
            last -= 1
            i += 1
        return i

```