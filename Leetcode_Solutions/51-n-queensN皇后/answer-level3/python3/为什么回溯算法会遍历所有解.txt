虽然通过了，但是有一处不解：为什么程序会遍历所有解


```python [class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.List = [-1]*n
        index = 0
        self.newlist = []
        self.helper(index, n)
        return self.newlist
        
    
    def helper(self, index, n):
        if index == n:
            newlist = []
            self.printresult(self.List,n)
            return 
        for i in range(n):
            self.List[index] = i
            if self.isValid(index, i):
                self.helper(index+1,n)
                
    def isValid(self, index, i):
        for j in range(index):
            if self.List[j] == i:
                return False
            if abs(self.List[index]-self.List[j]) == index - j:
                return False
        return True
            
    def printresult(self,List,n):
        strpoint = '.'
        strQ = "Q"
        newlist = []
        for i in range(n):
            newstr = strpoint*List[i] + strQ + strpoint*(n-1-List[i])
            newlist.append(newstr)
        self.newlist.append(newlist)
        return ]
```




