### 解题思路
感觉只要是字符串的题，都可以想想能不能用栈或者deque去暴力解决。

**本题关键思路**：应该是很多字符串尤其是涉及到括号相关的题目的通用思路，左边括号疯狂压入栈内（其实也就是用append），然后遇到一个匹配的右边括号，就把左边括号pop出去。所以，如果字符串有效，stack最终必定是空的。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        # 如果字符串是长度为单数，必定不是有效字符串
        if len(s) % 2:
            return False
        stack = []
        for c in s:
            # 只要是左边括号，就压入栈内
            if c in ["(", "[", "{"]:
                stack.append(c)
            elif len(stack):
                # 如果下一个是右边括号，且能够匹配之前压入的最后一个左括号，就是一对有效括号，那就清掉栈内的这个左边括号
                if c is ")" and stack[-1] is "(":
                    stack.pop()
                elif c is "]" and stack[-1] is "[":
                    stack.pop()
                elif c is "}" and stack[-1] is "{":
                    stack.pop()
                # 如果不匹配，那就gg
                else:
                    return False
            else:
                return False
        # 要是一直遇到的是左边括号，那这个栈就不是空的，那就gg
        if len(stack):
            return False
        # 当且仅当栈为空，才说明括号都能匹配
        else:
            return True
```