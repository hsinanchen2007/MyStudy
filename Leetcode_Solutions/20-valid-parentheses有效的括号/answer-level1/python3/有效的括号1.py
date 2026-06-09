### 解题思路
小白偷看答案
情况1：
都为有效括号，则弹出堆栈的key对应的value则为c；
情况2:
错序，【弹出堆栈的key对应的value不为c，stack长度不为1】

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'{': '}',  '[': ']', '(': ')', '?': '?'}
        stack = ['?']
        for c in s:
            if c in dic: stack.append(c)
            elif dic[stack.pop()] != c: return False 
        return len(stack) == 1
```