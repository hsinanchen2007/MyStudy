有点菜
```python []
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        
        remain = set()
        endpoint = set()
        temp = set()
        N = len(graph)

        for index,num in enumerate(graph):
            
            if num == []:
                endpoint.add(index)
            else:
                remain.add(index)      

        
        while True:
            for i in remain:
                for j in graph[i]:
                    if j in endpoint:
                        temp.add(i)
                    elif j in remain:
                        if i in temp:
                            temp.remove(i)
                        break
            if not(temp) :
                break
            else:
                endpoint =  endpoint | temp
                remain -= temp
                temp = set()
                
        res = list(endpoint)
        res.sort()
        return res
```
