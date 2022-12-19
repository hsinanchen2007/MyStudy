```
class Solution:
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        top=0
        right=len(matrix[0])-1
        bottom=len(matrix)-1
        left=0
        i=j=0
        n=len(matrix[0])*len(matrix)
        res=[]
        while True:
            while j<=right:
                res.append(matrix[i][j])
                if len(res)==n:
                    return res
                j+=1
            right-=1
            j-=1
            i+=1
            while i<=bottom:
                res.append(matrix[i][j])
                if len(res) == n:
                    return res
                i+=1
            bottom-=1
            i-=1
            j-=1
            while j>=left:
                res.append(matrix[i][j])
                if len(res) == n:
                    return res
                j-=1
            left+=1
            j+=1
            i-=1
            while i>top:
                res.append(matrix[i][j])
                if len(res) == n:
                    return res
                i-=1
            top+=1
            i+=1
            j+=1
```
