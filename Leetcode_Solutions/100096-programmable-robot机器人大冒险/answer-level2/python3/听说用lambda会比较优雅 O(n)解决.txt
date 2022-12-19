执行一次指令，把走过的路存入path字典中，key为横轴，value为纵轴列表
执行后得到一次指令的终点向量vector
定义向量的除法、减法、数乘、取模
定义命中（横轴在path.keys中，纵轴在其对应的值的列表中）
终点对向量取模，判断是否命中
将每个不越过终点的障碍物对向量取模，判断是否命中

```
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        vector=[0,0]
        path={}
        for cmd in command:
            if vector[0] not in path:
                path[vector[0]]=[vector[1]]
            else:
                path[vector[0]].append(vector[1])
            if cmd=='U':
                vector[1]+=1
            else:
                vector[0]+=1
        if vector==[0,0]:
            return True if [x,y]==[0,0] else False
        div=lambda a,b:min(a[0]//b[0] if b[0]!=0 else 1e9,a[1]//b[1] if b[1]!=0 else 1e9)
        sub=lambda a,b:[a[0]-b[0],a[1]-b[1]]
        mul=lambda a,b:[b*i for i in a]
        mod=lambda a,b:sub(a,mul(b,div(a,b)))
        hit=lambda a,b:a[0] in b.keys() and a[1] in b[a[0]]
        if not hit(mod([x,y],vector),path):
            return False
        for obstacle in obstacles:
            if obstacle[0]>x or obstacle[1]>y:
                continue
            if hit(mod(obstacle,vector),path):
                return False
        return True
```
