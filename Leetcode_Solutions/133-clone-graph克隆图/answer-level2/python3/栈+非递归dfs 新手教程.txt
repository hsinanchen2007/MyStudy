这道题是leetCode探索里中讲解栈+dfs的课后练习题，故用栈+DFS解一波。

1. DFS算法组成的3元素：栈，节点，已访问的集合
    - 栈：后入先出的容器；
    - 节点：单独的类，本题就是Node的实例了，包括value和neighbors;
    - 已访问集合：为了避免重复入栈死循环。本题中用rst代替了。

2. DFS算法套路：
    1. 初始化三元素：
        `
        node = Node(n)  ##本题中默认就是Node实例，故略
        stack = [node]  
        rst = {node:Node(node.val,[])}
        `
    2. 操作栈--弹出栈顶：
        `vertex = stack.pop()`
    3. 操作弹出的节点--根据业务生成子节点（一个或多个）：
        `for vertex_neigh in vertex.neighbors:`
    4. 判断这些节点并执行业务逻辑操作--不在已访问集合，则入栈，并加入已访问集合，再将这些节点加入弹出节点的neighbors：
        ```
        if vertex_neigh not in rst.keys():
            
            rst[vertex_neigh] = Node(vertex_neigh.val,[])
            stack.append(vertex_neigh)
            
        rst[vertex].neighbors.append(rst[vertex_neigh])```
    5. 完成遍历后返回：
        `return rst[node]`

3. 本题代码：
    ```
    """
    # Definition for a Node.
    class Node:
        def __init__(self, val, neighbors):
            self.val = val
            self.neighbors = neighbors
    """

    class Solution:
        
        def cloneGraph(self, node: 'Node') -> 'Node':
            
            stack = [node]
            rst = {node:Node(node.val,[])}
            
            while stack:
                
                vertex = stack.pop()
                
                for vertex_neigh in vertex.neighbors:
                    
                    if vertex_neigh not in rst.keys():
                        
                        rst[vertex_neigh] = Node(vertex_neigh.val,[])
                        stack.append(vertex_neigh)
                        
                    rst[vertex].neighbors.append(rst[vertex_neigh])

            return rst[node]  

    ```

