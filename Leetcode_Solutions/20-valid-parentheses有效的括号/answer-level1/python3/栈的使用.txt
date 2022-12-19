### 解题思路
    感觉就是栈的使用，在进行括号的检测过程中，初始化一个数组，用来存放括号。
设置一个while循环，首先会有左括号进栈，然后检测下一个进栈的是不是对应的有括号，若是对用的右括号，就把括号的左缓存清掉，若仍是左括号，就可以继续缓存，依次循环，但是最好要注意，我们的括号缓存最好要完全清除完，这样才是所有的括号完全匹配的情况

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        i = 0
        stack =[0]* len(s)
        m = 0
        while i<len(s):
            print(s[i])
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                stack[m] = s[i]
                m = m + 1
            if s[i] == ')' or s[i] == ']' or s[i] == '}':
                if stack[m-1] =='(' and s[i] == ')' or stack[m-1] =='[' and s[i] == ']'or stack[m-1] =='{' and s[i] == '}':
                    m = m - 1
                else:
                    return False
            i = i + 1
        if m !=0 :
            return False
        return True

```