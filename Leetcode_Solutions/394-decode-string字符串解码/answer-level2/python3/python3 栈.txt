
```python
class Solution:
    def decodeString(self, s: str) -> str:
        num = ''
        numStack, strStack = [], []
        for st in s:
            if st.isdigit():
                num += st
            elif st == '[':
                numStack.append(int(num))
                strStack.append(st)
                num = ''
            elif st == ']':
                tempStr = ''
                a = strStack.pop()
                while a != '[':
                    tempStr = a + tempStr
                    a = strStack.pop()
                
                strStack.append(numStack.pop() * tempStr)
            else:
                strStack.append(st)
        return ''.join(strStack)



```