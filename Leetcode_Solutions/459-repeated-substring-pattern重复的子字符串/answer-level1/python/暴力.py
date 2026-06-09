## 思路:

思路一：

该方法最容易想，就是找前缀，看`s`是否能有几个这样前缀组成。

思路二：

我们知道如果`s`是重复字符串，那么可以由两个子串组成。我们通过`ss = s + s`就有4个子串组成，

删除首尾字母，那么 `ss[1:-1]`就有应该有2个子串组成，就是说`ss[1:-1]`是否存在`s`

## 代码:

思路一：

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1, len(s) // 2 + 1):
            a, b = divmod(n, i)
            if b == 0 and s[:i] * a  == s:
                return True
        return False
```

思路二：

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return (s+s)[1:-1].find(s) != -1
```

