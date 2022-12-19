class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack=[]
        f=[0]*len(s)
        for i in range(len(s)):
            if s[i]=='(':
                stack.append(i)
            else:
                if len(stack)!=0 and s[stack[0]]=='(':
                    f[i]=1
                    f[stack[-1]]=1
                    stack.pop()
        result=0
        x=0
        for i in f:
            if i==0:
                result=max(result,x)
                x=0
            else:
                x=x+1
        result=max(x,result)
        return result
