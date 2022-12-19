### 解题思路
是左括号，进栈；是右括号，判断栈顶是不是相应的左括号

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        # 先进后出，栈
        stack = []
        mapping = {")": "(", "}": "{", "]": "["}

        # For every bracket in the expression.
        for char in s:
            # If the character is an closing bracket
            if char in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)

        return not stack

            
```