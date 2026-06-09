```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        # 使用栈stack来记录左括号和右括号，所有的
        # 将所有的非外层括号保存到字符串result中
        stack = []
        result = ""
        
        for each in S:
            if each == "(":    
                if stack: # 如果栈是空的话
                    result+=each # 表示当前"("是最外层括号
                stack.append(each) # 添加当前的"("到栈中
            else:
                stack.pop() # 把与"("匹配的括号从队列中弹出
                if stack:   # 如果"("不是队列中的最后一个, 加到result中
                    result+=each
                    
        return result
```
