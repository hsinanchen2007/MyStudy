### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        stack = []
        for i in S:
            if i != ")":
                stack.append(i)
            else:
                temp = 0
                #如果是左括号，直接放进去
                if stack[-1] =="(":
                    temp +=1
                    stack.pop()
                    stack.append(temp)
                else:
                    #把中间的值加起来，然后乘以2，再放进栈
                    while stack[-1] !="(":
                        temp += stack.pop()
                    stack.pop()
                    stack.append(2*temp)

        #栈里面的值相加
        res = 0
        for value in stack:
            res += value
        return res
```