### 解题思路
利用栈，遍历整个字符串s，如果为左括号('('/'{'/'[')则入栈，遇到右括号(')'/'}'/']')则判断是否与栈顶的左括号匹配，如果匹配则栈顶元素出栈，否则返回False。最后判断栈中元素个数，，如果为1则返回True，否则返回False。
注意：初始化栈时添加一个元素，防止访问栈顶时，元素不存在报错

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = ['?']
        dic = {'(':')','{':'}','[':']','?':'?'}
        for i in s:
            if(i == '(' or i == '{' or i == '['):
                stack.append(i)
            else:
                if(i ==dic[stack[-1]]):
                    stack.pop()
                else:
                    return False
        if(len(stack)==1):
            return True
        else:
            return False
                
            
            
            
                
```