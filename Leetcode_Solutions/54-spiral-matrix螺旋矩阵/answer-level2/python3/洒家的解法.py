```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        direction=[[0,1],[1,0],[0,-1],[-1,0]]
        result=[]
        rows=len(matrix)
        if rows<=0:
            return result
        cols=len(matrix[0])
        if cols<=0:
            return result
        visited=[]
        for i in range(rows):
            visited.append([0 for i in range(cols)])
        count=[]
        cur=[0,0]
        dcount=0
        while len(count)<rows*cols:
            result.append(matrix[cur[0]][cur[1]])
            count.append([cur[0],cur[1]])
            visited[cur[0]][cur[1]]=-1
            temprow=cur[0]+direction[dcount][0]
            tempcol=cur[1]+direction[dcount][1]
            if temprow>=rows or temprow<0 or tempcol>=cols or tempcol<0 or visited[temprow][tempcol]==-1:
                dcount=(dcount+1)%4
                temprow=cur[0]+direction[dcount][0]
                tempcol=cur[1]+direction[dcount][1]
            cur[0]=temprow
            cur[1]=tempcol
        print(count)
        return result
```
