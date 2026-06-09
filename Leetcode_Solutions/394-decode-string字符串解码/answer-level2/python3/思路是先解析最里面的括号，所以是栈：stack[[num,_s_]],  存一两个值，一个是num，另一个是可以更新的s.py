### 解题思路
stack[[num,"s"]],  
存一两个值，一个是num，另一个是可以更新的s
当遇到【 的时候入栈【num，和s】
如果只是abc，则更新s就行
如果 】解析num和ta的str，然后加到前一个去stack[-1][0]==['abc',num]

### 代码

```python3
class Solution:
    def decodeString(self, s: str) -> str:

        stack = []
        stack.append(['', 1])
        num = ''

        for ch in s:
            
            if ch.isdigit():
                num += ch
            elif ch == '[':
                stack.append(['', int(num)])
                num = "" #注意重置这个数字
            elif ch == ']':
                chs, k = stack.pop() 
                stack[-1][0] += k*chs
            else:
                stack[-1][0] += ch
        
        return stack[0][0]

```