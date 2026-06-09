```
class Solution(object):
    def __init__(self):
        self.string=[]
    def find(self,n,m,s):
        if n==0 and m==0:
            self.string.append(s)
        else:
            if n>0 :self.find(n-1,m,s+"(")
            if n<m: self.find(n,m-1,s+")")
        
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.find(n,n,"")
        return self.string
```
