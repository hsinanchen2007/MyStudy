### 解题思路

kick the card. 
Again, I will give you the code. 

### 代码

```python3
def count(a,b):
    return a//10+a%10+b//10+b%10
    
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        log=[[0 for i in range(n)] for j in range(m)]
        queue=[[0,0]]
        log[0][0]=1

        while len(queue)!=0:
            tmp=[]
            i=queue[0][0]
            j=queue[0][1]
            del(queue[0])
            if i>0:
                tmp.append([i-1,j])
            if j>0:
                tmp.append([i,j-1])
            if i<m-1:
                tmp.append([i+1,j])
            if j<n-1:
                tmp.append([i,j+1])
            for point in tmp:
                i=point[0]
                j=point[1]
                if log[i][j]==1:
                    continue
                elif count(i,j)<=k:
                    log[i][j]=1
                    queue.append([i,j])
        
        out=0
        for i in range(m):
            out+=log[i].count(1)
        return out
```