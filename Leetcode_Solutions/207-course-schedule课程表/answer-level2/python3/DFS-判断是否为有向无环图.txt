    class Solution:
        def canFinish(self, num: int, pre: List[List[int]]) -> bool:
            if not num and pre:
                return 
            from collections import defaultdict
            #首先是构建图
            graph = defaultdict(list)
            for k,v in pre:
                graph[k].append(v)
            #设置flag:
            visited = [0] * num
            for i in range(num):
                if not self.dfs(graph,visited,i):
                    return False
            return True
        #dfs判断是否为有向无环图：0：未访问，1：正访问，2：已访问完
        def dfs(self,graph,visited,i):
            if visited[i] ==1:
                return False
            if visited[i]==2:
                return True
            visited[i]=1     #默认设置为1
            for j in graph[i]:
                if not self.dfs(graph,visited,j):
                    return False
            visited[i] = 2
            return True
            
        