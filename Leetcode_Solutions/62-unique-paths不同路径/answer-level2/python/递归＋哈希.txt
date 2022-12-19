class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return self.recur(m,n,{})
    
    def recur(self,m,n,dic):
        if n==1:
            return 1
        if m==1:
            return 1
        if (m,n) in dic:
            return dic[(m,n)]
        dic[(m,n)]=self.recur(m,n-1,dic)+self.recur(m-1,n,dic)   
        return dic[(m,n)]
        