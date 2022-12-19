### 解题思路
考虑以下几种情况：
清空x,y
装满x,y
x倒入y
y倒入x

开始使用的dfs，但是会超过python的最大递归深度，于是改成了bfs，用list模型队列

### 代码

```python3
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        Set = set()
        queue = list()
        queue.append((0,0))

        def add_status(real_x,real_y,queue,Set):
            status = '{},{}'.format(real_x,real_y)
            if status in Set:
                return
            queue.append((real_x,real_y))
            Set.add(status)

        while len(queue)>0:
            real_x, real_y = queue.pop(0)
            if real_x==z or real_y==z or real_x+real_y==z: #满足条件
                return True
            add_status(x,real_y,queue,Set) #装满x
            add_status(real_x,y,queue,Set) #装满y
            add_status(0,real_y,queue,Set) #清空x
            add_status(real_x,0,queue,Set) #清空y
            # x倒入y
            if real_x>0:
                if real_x <= y-real_y: #y剩余容量能够装下x
                    add_status(0,real_y+real_x,queue,Set)
                else:
                    tran = y-real_y # 实际转移容量
                    add_status(real_x-tran,real_y+tran,queue,Set)
            # y倒入x
            if real_y>0:
                if real_y < x - real_x:
                    add_status(real_x+real_y,0,queue,Set)
                else:
                    tran = x - real_x
                    add_status(real_x+tran,real_y-tran,queue,Set)
        
    
        def dfs(real_x, real_y,x,y,z):
            if real_x==z or real_y==z or real_x+real_y==z:
                return True
            if '{},{}'.format(real_x,real_y) in Set: # 搜索过
                return False
            Set.add('{},{}'.format(real_x,real_y))
            flag = False
            flag = flag or dfs(x,real_y,x,y,z) #装满x
            flag = flag or dfs(real_x,y,x,y,z) #装满y
            flag = flag or dfs(0,real_y,x,y,z) #清空x
            flag = flag or dfs(real_x,0,x,y,z) #清空y
            # x倒入y
            if real_x>0:
                if real_x <= y-real_y: #y剩余容量能够装下x
                    flag = flag or dfs(0,real_y+real_x,x,y,z)
                else:
                    tran = y-real_y # 实际转移容量
                    flag = flag or dfs(real_x-tran,real_y+tran,x,y,z)
            # y倒入x
            if real_y>0:
                if real_y < x - real_x:
                    flag = flag or dfs(real_x+real_y,0,x,y,z)
                else:
                    tran = x - real_x
                    flag = flag or dfs(real_x+tran,real_y-tran,x,y,z)
            return flag
        return False
            
```