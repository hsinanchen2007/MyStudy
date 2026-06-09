```
class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        
        outcoming=dict()
        for u,v in edges: #因为是无定向图，来回路径都记录一下
            outcoming[u] = outcoming.get(u,[]) +[v]
            outcoming[v] = outcoming.get(v,[]) + [u]
        
        def dfs(u,v,discovered=None):
            if discovered == None:
                discovered = {}
            if u in discovered:
                return
            else:
                discovered[u] = None
                if v in outcoming[u]: # 因为本身edge的存在，保证了一定有1解路径，我们是想寻找有没有多于1解的路径。
                    result.append(1)
                    discovered[v] = None
                for each in outcoming[u]:
                    dfs(each,v,discovered)
                
            
        for u, v in edges[::-1]: #倒过来看，保证能输出 最后1个多余路径
            result = []
            dfs(u,v)
            if len(result) >1: #除了edge本身，还有1个办法从u走到v，则return
                return [u,v]
```
