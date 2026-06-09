### 解题思路
辅助栈的运用

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'(':')', '{':'}', '[':']'}
        if len(s) == 0:
            return True

        stack = ['#'] # 在栈中添加一个元素，防止stack[-1]索引出界
        for i in s:
            # 如果为括号的前一半，则添加其对应的后一半到栈中
            if i in dic.keys():
                stack.append(dic[i])
            # 如果为括号的后一半，则看其是否与栈顶元素相同
            # 相同即删去栈顶元素，不相同则不是合理括号，直接返回False
            elif i == stack[-1]:
                stack.pop()
            else:
                return False
        # 最后查看栈内是否只有一个初始元素
        return len(stack) == 1
        


                


```