康不懂官方第一种方法，于是直接用栈来做，类似逆波兰表达式的意思，如果碰到`()`中间没数字就自己补1，加完后再放到栈里，如果遍历到‘)’而待出栈的不是‘(’时，那每出栈一个‘(’都要把中间夹的数字乘2，最后会得到各个可分割的(),再求和就好了。
```
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        stack = []
        for i in S:
            if i=='(':
                stack.append('(')
            else: 
                if stack[-1]=='(':
                    stack[-1]=1
                else:
                    tmp=stack.pop()
                    count=0
                    while tmp!='(':
                        count+=tmp
                        tmp=stack.pop()
                    stack.append(count*2)
        return sum(stack)

```
过了一会发现幂次主要跟前面套了几层括号有关,只用一个变量记录当前有几层‘(’括号，该位置就是几次幂。另一个变量记录总数，碰到‘)’幂次减一就行了。与栈的思想其实是一样的，重点都在于后面的')'该怎么处理。建议细细试一试这种方法。
```
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        i=0
        count=0
        mi=-1
        while i<len(S):
            if S[i]=='(':
                mi+=1
                i+=1
            elif mi>=0:
                count+=2**mi
                mi-=1
                while i+1<len(S) and S[i+1]!='(':
                    mi-=1
                    i+=1
                i+=1
            print (i,count)
        return count
```

