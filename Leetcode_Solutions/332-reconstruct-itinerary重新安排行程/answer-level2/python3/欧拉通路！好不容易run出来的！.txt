1. 如何求解欧拉通路的问题呢？
    使用基于递归实现深度优先遍历（非递归也可以实现），所谓欧拉通路指的是：一笔画，即不重复的经过一个图的所有边，顶点可重复！递归过程中存在回溯，如果只递归不回溯，并且遍历完所有的边，这样就能求得欧拉通路！

2. 对比普通的深度优先遍历，实现欧拉通路求解？
    需要注意的点：
    (1) 使用字典类型存储已访问的边；
    (2) 对于两点之间、同一方向，存在多条边的情况，可以用元组('a-b', 1)、('a-b', 2)进行区分
    (3) 终止判定条件: 完成一次欧拉通路后，应该遍历完了所有的边
```
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = {}
        for from_, to_ in tickets:
            if from_ not in graph:
                graph[from_] = {to_:1}
            elif to_ in graph[from_]:
                graph[from_][to_] += 1
            else:
                graph[from_][to_] = 1
        
        for key in graph:
            values = sorted(graph[key].items())
            new_values = []
            for val, num in values:
                for i in range(num):
                    new_values.append((val, i))
            graph[key] = new_values
        
        self.visited = {}
        self.res = []
        def dfs(pla, e):   
            if pla not in self.visited:
                self.visited[pla] = set()
            
            if len(e) >= len(tickets):
                self.res = e
            
            if pla in graph and len(self.res) == 0:
                for (target, num) in graph[pla]:
                    if (target, num) in self.visited[pla]:
                        continue
                    self.visited[pla].add((target, num))
                    if len(e) == len(tickets) - 1:
                        dfs(target, e + [pla, target])
                    else:
                        dfs(target, e + [pla])
                    self.visited[pla].remove((target, num))
            
        dfs('JFK', [])
        return self.res
```
