## 思路:

思路一：`split`函数

思路二：每个单词前面都有一个空格（除第一个单词）

## 代码:

思路一：

```python
class Solution:
    def countSegments(self, s: str) -> int:
        return len(s.split())
```

思路二：

```python
class Solution:
    def countSegments(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            if s[i] != " " and (i == 0 or s[i - 1] == " "):
                res += 1
        return res
```

