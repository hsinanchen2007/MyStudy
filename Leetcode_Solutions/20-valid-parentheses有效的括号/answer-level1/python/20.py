### 解题思路
使用栈：
1、处理特殊情况：s为“”返回True
2、左括号入栈，右括号跟栈顶匹配，匹配出栈，不匹配返回False（注意此时要判断list长度是否大于0）

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if s == "":
            return True
        list_s = []
        for i in range(len(s)):
            if s[i] in ["(", "[", "{"]:
                list_s.append(s[i])
            if s[i] in [")", "]", "}"]:
                if s[i] == ")" and len(list_s) > 0 and list_s[-1] == "(":
                    list_s.pop()
                elif s[i] == "]" and len(list_s) > 0 and list_s[-1] == "[":
                    list_s.pop()
                elif s[i] == "}" and len(list_s) > 0 and list_s[-1] == "{":
                    list_s.pop()
                else:
                    return False
        if len(list_s) == 0:
            return True
        else:
            return False
            
```