BFS 其实是很简单的基础算法，抓住如下几点即可轻松写出不易错的 baseline:

1. BFS 算法组成的 3 元素：队列，入队出队的节点，已访问的集合。
    - 队列：先入先出的容器；
    - 节点：最好写成单独的类，比如本例写成 `(value,step)` 元组。也可写成 `(value,visited)`，看自己喜好和题目；
    - 已访问集合：为了避免队列中插入重复的值

2. BFS算法组成的套路：
    1. 初始化三元素：
        `
        Node = node(n)
        queue = [Node]
        visited = set([Node.value])`
    2. 操作队列 —— 弹出队首节点：
        `vertex = queue.pop(0)`
    3. 操作弹出的节点 —— 根据业务生成子节点（一个或多个）：
        `[node(vertex.value - n*n, Node.step+1) for n in range(1,int(vertex.value**.5)+1)]`
    4. 判断这些节点 —— 符合业务条件，则return，不符合业务条件，且不在已访问集合，则追加到队尾，并加入已访问集合：
        ```
        if i==0:                   
            return new_vertex.step
                    
        elif i not in visited:
            queue.append(new_vertex)
            visited.add(i)```
    5. 若以上遍历完成仍未return，下面操作返回未找到代码：
        `return -1`

3. 本题代码：
    
```python
class node:
    def __init__(self,value,step=0):
        self.value = value
        self.step = step
    def __str__(self):
        return '<value:{}, step:{}>'.format(self.value,self.step)


class Solution:
    def numSquares(self, n: int) -> int:
        queue = [node(n)]
        visited = set([node(n).value])
        
        while queue:
            vertex = queue.pop(0)
            residuals = [vertex.value - n*n for n in range(1,int(vertex.value**.5)+1)]
            for i in residuals:
                new_vertex = node(i, vertex.step+1)
                if i==0:                   
                    return new_vertex.step
                    
                elif i not in visited:
                    queue.append(new_vertex)
                    visited.add(i)
                                        
        return -1
```
