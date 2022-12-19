### 解题思路
整体思路是先找到字符串中每个整体部分，当字符为"("时入栈，为“)”时出栈，当栈的长度为0时，得到的临时字符串一定为包含最外层括号的一个整体，然后把临时字符串去掉第一个和最后一个字符就是第一个原语，放入结果变量中，以此类推可以找到第二个原语。

### 代码

```python3
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack_E = [] #括号栈
        res = ''
        temp = '' #存储临时字符串
        for i in S:
            if i == "(":
                stack_E.append(i)
            else:
                stack_E.pop()
            temp += i
            if len(stack_E) == 0:
                res += temp[1:-1] #去掉临时字符串的第一个和最后一个字符
                temp = ''
        return res

```