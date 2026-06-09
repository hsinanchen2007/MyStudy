  ## 思路:

思路一：递归

我们用栈找到每一个括号`[`对应的 `]`的位置，用递归求出结果。里面有重复计算，不知道大家有木有好办法可以减少。

```python
class Solution:
    def decodeString(self, s: str) -> str:
        # 找到括号的匹配位置
        def matchBracket(s):
            pairBracket = {}
            stack = []
            for idx, val in enumerate(s):
                if val == "[":
                    stack.append(idx)
                if val == "]":
                    pairBracket[stack.pop()] = idx
            return pairBracket

        # print(pairBracket)

        def helper(s, pairBracket):
            if "[" not in s:
                return s
            left_p = s.find("[")
            right_p = pairBracket[left_p]
            i = 0
            while not s[i].isdigit():
                i += 1
            return s[:i] + int(s[i:left_p]) * helper(s[left_p + 1: right_p], matchBracket(s[left_p + 1: right_p])) + \
                   helper(s[right_p + 1:], matchBracket(s[right_p + 1:]))
            

        return helper(s, matchBracket(s))
```

还有一种递归，也很好理解。

```python
class Solution:
    def decodeString(self, s: str) -> str:
        pos = 0
        def helper():
            nonlocal pos
            num = 0
            word = ""
            while pos < len(s):
                cur = s[pos]
                if cur == '[':
                    pos += 1
                    curStr = helper()
                    word += num * curStr
                    num = 0
                elif cur.isdigit():
                    num = num * 10 + int(cur)
                elif cur == ']':
                    return word
                else:
                    word += cur
                pos += 1
            return word

        return helper()
```



思路二：迭代

模拟递归过程

```python
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        curStr = ""
        curNum = 0
        for a in s:
            if a == '[':
                stack.append(curNum)
                stack.append(curStr)
                curStr = ""
                curNum = 0
            elif a.isdigit():
                curNum = curNum * 10 + int(a)
            elif a == ']':
                curStr = stack.pop() + stack.pop() * curStr
            else:
                curStr += a
        return curStr
```