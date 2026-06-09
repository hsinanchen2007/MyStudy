> 建图+拓扑排序
```python
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        
        self.graph = {}
        self.nodes = set()
        for word in words:
            self.nodes = self.nodes | set(word)
        
        def build_graph(words):
            if len(words) <= 1:
                return
            tmp = []
            prev = None
            for word in words:
                if word[0] != prev and prev:
                    build_graph(tmp)
                    tmp = []
                    self.graph[prev] = self.graph.get(prev,set())|{word[0]}
                if word[1:]:
                    tmp.append(word[1:])
                prev = word[0]
            build_graph(tmp)
                    
        build_graph(words)
        print(self.graph)
        
        def toposort(graph):
            degree = {v:0 for v in self.nodes}
            for u in graph:
                for v in graph[u]:
                    degree[v] += 1
            zero = [i for i in degree if degree[i] == 0]
            res = []
            while zero:
                u = zero.pop()
                res.append(u)
                for v in self.graph.get(u,[]):
                    degree[v] -= 1
                    if degree[v] == 0:
                        zero.append(v)
            if len(res) == len(self.nodes):
                return ''.join(res)
            else:
                return ''
        
        return toposort(self.graph)
```