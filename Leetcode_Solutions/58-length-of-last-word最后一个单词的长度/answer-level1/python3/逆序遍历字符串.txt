### 解题思路
逆序遍历找到最后一个空格的位置，空格的index即最后一个字符串的长度，注意两点：
（1）末尾的空格要去掉
（2）如果没有空格，则只有一个字符串，输出字符串长度即可


### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        if " " not in s:
            return len(s)
        for index, ch in enumerate(s[::-1]):
            if ch == " ":
                return index
```