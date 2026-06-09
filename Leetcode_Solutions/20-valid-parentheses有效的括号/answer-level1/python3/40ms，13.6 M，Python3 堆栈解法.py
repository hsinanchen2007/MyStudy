## 解题思路

这道题用堆栈会很好解

新符号和栈顶相配对，就把栈顶的字符出栈

同时利用 map 能省去写 if 的时间，注意是右符号配对左符号

另外有两个 tip

=== True 的字符串一定是偶数个字符

这个比较好理解，括号都是成双成对的

=== 空栈时只有左括号可以进入

按照我的解法，遍历时遇到右括号会把其和栈顶符号配对，也就是 `array[-1]`，但是如果当前是空的，那么就会 out of range。
所以干脆加个判断，如果栈空且遇到右括号，直接返回 False。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:

        parentheses = {
            ")" : "(",
            "]" : "[",
            "}" : "{"
        }

        if len(s) == 0:
            return True
        if len(s) % 2 != 0:
            return False

        array = []

        for x in range(len(s)):
            if s[x] in parentheses:
                if len(array) == 0:
                    return False
                elif array[-1] == parentheses[s[x]]:
                    array.pop()
            else:
                array.append(s[x])

        if len(array) != 0:
            return False
        return True
```