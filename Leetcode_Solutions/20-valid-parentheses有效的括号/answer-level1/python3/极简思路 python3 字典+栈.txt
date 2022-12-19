思路：

字典储存对应括号

遍历字符串：
左括号入栈
右括号分三种情况：
1.若此时栈为空，直接返回False
2.若此时右括号和栈顶左括号不匹配，直接返回False
3.若此时右括号和栈顶左括号匹配，栈顶左括号出栈

遍历结束后
若栈为空栈，说明所有括号都匹配完成，返回True
否则，返回False
```
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'(':')','[':']','{':'}'}
        stack = []
        for i in s:
            if i in dic:
                stack.append(i)
            else:
                if len(stack) == 0:
                    return False
                elif i == dic[stack.pop()]:
                    pass
                else:
                    return False
        return len(stack) == 0
```

