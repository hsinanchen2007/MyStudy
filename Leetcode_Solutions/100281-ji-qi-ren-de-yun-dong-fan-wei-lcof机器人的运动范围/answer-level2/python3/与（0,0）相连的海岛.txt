### 解题思路
其实就是LeetCode的200.海岛问题
寻找的就是与（0,0）相连的岛屿个数
因此使用相同的回溯就可以实现

### 代码

```python3
def __init__(self):
    self.res = 0
```
```python3
def movingCount(self, m: int, n: int, k: int) -> int:

        if k==0:
            return 1 
        marked = [[0]*n for _ in range(m)]       
        def backtrack(pos_x,pos_y):
            marked[pos_x][pos_y] = 1
            self.res+=1
            
            for x,y in [(-1,0),(1,0),(0,1),(0,-1)]:
                tmp_x = x+pos_x
                tmp_y = y+pos_y
                if 0<=tmp_x< m and 0<=tmp_y< n and not marked[tmp_x][tmp_y] \
                        and tmp_x%10+tmp_x//10+tmp_y%10+tmp_y//10 <= k:
                    backtrack(tmp_x,tmp_y)
                    
        backtrack(0,0)
        
        return self.res
```
