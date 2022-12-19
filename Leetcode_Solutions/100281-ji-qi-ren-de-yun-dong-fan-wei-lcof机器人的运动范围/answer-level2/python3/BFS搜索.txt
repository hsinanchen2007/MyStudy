### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        '''
        0,0,0 m=x
        n=y
        0,0,0
        '''
        stack1=[(0,0)]
        visited= [[False for _ in range(n)] for _ in range(m)]
        total=0
        while stack1:
            cur_x,cur_y = stack1.pop(0)
            if visited[cur_x][cur_y]:
                continue   
            visited[cur_x][cur_y]=True
            total+=1
            if cur_x+1<m:
                a = self.help(cur_x+1)
                b = self.help(cur_y)
                if a+b<=k:
                    stack1.append((cur_x+1,cur_y))
            if cur_y+1<n:
                a = self.help(cur_x)
                b = self.help(cur_y+1)
                if a+b<=k:
                    stack1.append((cur_x,cur_y+1))
        return total
                
                
    def help(self,num):
        if num<10:return num
        elif num>99:
            return num%100
        else:
            return num//10+num%10    
                    
                
```