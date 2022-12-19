我一开始 random取了1个起始点，发现答案不太对。之后仔细一想，才发现这个图并不是保证一定是连通的，所以只能对于每个点都做BFS双染色。
```
class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        def dfs(start):
            red = {}
            blue = {}
            startpoint = [start]
            queue = ("red",startpoint)
            while len(queue[1])>0:
                color,thislevel = queue[0],queue[1]
                next_level = set()
            
                if color == "red": #当前层是红色的话
                    for each in thislevel:
                        if each not in red and each not in blue: #尚未染色，则给他染上红色
                            red[each] = None
                            next_level.update(outcoming[each]) #把这个新点的children加入下一层level，我们用set
                        elif each in red: #OK，已经正确染色
                            pass
                        elif each in blue: #Wow,染色错了，不能两分，return False
                            return False
                    queue =("blue",list(next_level))
                elif color == "blue": #同上
                    for each in thislevel:
                        if each not in red and each not in blue:
                            blue[each] = None
                            next_level.update(outcoming[each])
                        elif each in blue:
                            pass
                        elif each in red:
                            return False
                    queue =("red",list(next_level))
            return True
                    
        outcoming = {}
        for index in range(len(graph)):
            outcoming[index] = graph[index]
        for each in outcoming.keys():
            if dfs(each):
                continue
            else:
                return False
        return True
```
