```
class Solution:
    def findRedundantConnection(self, edges):
        n = 0
        for edge in edges:
            n = max(n,max(edge))
        pa_n = list(range(n+1))
        def getpa(x):
            tmp = []
            while pa_n[x]!=x:
                tmp.append(x)
                x = pa_n[x]
            ans = x
            for x in tmp:
                pa_n[x] = ans
            return ans
        def merge(a,b):
            pa = getpa(a)
            pb = getpa(b)
            if pa!=pb:
                pa_n[pb] = pa
        for edge in edges:
            a = getpa(edge[0])
            b = getpa(edge[1])
            if a == b:
                res = edge
            else:
                merge(edge[0],edge[1])
        return res
print(Solution().findRedundantConnection([[1,2], [2,3], [3,4], [1,4], [1,5]]))

```
