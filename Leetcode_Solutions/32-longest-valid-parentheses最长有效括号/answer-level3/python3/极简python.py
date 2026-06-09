匹配的括号在出栈后会丢失掉这段长度信息，因此如果加一个记录之前匹配过的长度的字段则可解决。


```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []  # (char, former_len)
        max_len = 0
        count = 0
        for c in s:
            if c == ")" and len(stack) > 0 and stack[-1][0] == "(":
                _, former = stack.pop()
                count += 2 + former
                if count > max_len:
                    max_len = count
            else:
                stack.append((c, count))
                count = 0
            # print(stack)

        return max_len
```
