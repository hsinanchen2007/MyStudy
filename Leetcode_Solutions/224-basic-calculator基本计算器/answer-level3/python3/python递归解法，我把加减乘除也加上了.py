```
class Solution:
    def calculate(self, s) :
        res = self.helper(s,0)
        return res[0]

    def helper(self,s,start):
        num = 0
        stack = []
        i = start
        while i<len(s) and s[i]!= ")":
            if s[i].isdigit():
                num = num * 10 + int(s[i])
                i+= 1
            elif s[i] in ["+","-","*","/"]:
                self.addnum(stack,num)
                stack.append(s[i])
                num = 0
                i += 1
            elif s[i] == "(":
                sums,next = self.helper(s,i+1)
                i = next
                stack.append(sums)
            else:
                i += 1
                continue
        self.addnum(stack, num)
        sums = self.getsum(stack)
        return (sums,i+1)

    def getsum(self,stack):
        res = 0
        flag = True
        for i in stack:
            if i =="+":
                flag = True
            elif i =="-":
                flag = False
            else:
                if flag:
                    res += i
                else:
                    res -= i
        return res

    def addnum(self,stack,num):
        if len(stack) != 0 and stack[-1] == "*":
            stack.pop()
            pre = stack.pop()
            stack.append(int(pre*num))
        elif len(stack) != 0 and stack[-1] =="/":
            stack.pop()
            pre = stack.pop()
            stack.append(int(pre / num))
        else :
            stack.append(num)
```
