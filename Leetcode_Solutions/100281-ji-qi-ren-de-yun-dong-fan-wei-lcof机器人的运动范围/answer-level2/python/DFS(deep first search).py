### 解题思路
DFS: first we have to understand what is real DFS. I think in those solutions it is not enough clear to expalin what is DFS.
in my opiion: the key for the DFS is the code excute order in Runing. for example anyway the first to excute code must be [i+1,j] it means that we will run till we reach the boundary and now we will return to [i,j] and go on searching
but for BFS we will first step search in direction [0,1] and next step(I would rather name it timestep) in [0,1] so the key for BFS and DFS is the code excute time not same 

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def sum(i):
            if i>=10:
              sum=i%10+i//10
            else:
              sum=i
            return sum
#DFS just in one direction to search
 

        answer=[]
        def dfs(x,y):
           if x>=m or y>=n or sum(x)+sum(y)>k or (x,y) in answer:
                return 0
           else:
                answer.append((x,y))
                #print(answer)
                return 1+dfs(x+1,y)+dfs(x,y+1)
          
        return dfs(0,0)
```