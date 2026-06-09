
```python []
class Solution:
    def calculate(self, s: str) -> int:
        s=s.replace(' ','')
        stack=[]
        #先压入一个1进栈，可以理解为有个大括号在最外面
        stack.append(1)
        i=0
        res = 0
        sign=1
        while i<len(s):
            if s[i]=='+':
                sign=1
                i+=1
            elif s[i]=='-':
                sign=-1
                i+=1
            elif s[i]=='(':
                stack.append(sign*stack[-1])
                sign=1
                i+=1
            elif s[i]==')':
                stack.pop()
                i+=1
            else:
                num=''
                while i<len(s) and s[i].isdigit():
                    num+=s[i]
                    i+=1
                res+=int(num)*sign*stack[-1]
        print(res)
        return res

```
题目条件说明只有加减法和括号，由于加减法是相同顺序的，我们大可以直接把所有数顺序计算。难点在于多了括号后如何处理正负号。我们想象一下如果没有括号这题该怎们做：因为只有加减号，我们可以用一个变量sign来记录上一次的符号是加还是减，这样把每次读到的数字乘以这个sign就可以加到总的结果中了。有了括号后，整个括号内的东西可一看成一个东西，这些括号内的东西都会受到括号所在区域内的正负号影响（比如括号前面是个负号，然后括号所属的括号前面也是个负号，那该括号的符号就是正号）。但是每多一个括号，都要记录下这个括号所属的正负号，而每当一个括号结束，我们还要知道出来以后所在的括号所属的正负号。根据这个性质，我们可以使用一个栈，来记录这些括号所属的正负号。这样我们每遇到一个数，都可以根据当前符号，和所属括号的符号，计算其真实值。