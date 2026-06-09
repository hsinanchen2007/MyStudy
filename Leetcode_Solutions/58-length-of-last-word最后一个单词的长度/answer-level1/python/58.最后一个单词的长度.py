### 解题思路
- 去掉首尾的空格' '
- 以空格为''为间隔切割字符串
- 计算最后一个字符串的长度

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.strip().split(' ')[-1])
```