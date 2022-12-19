Python3：时间效率超过100%
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        return self.onecircle(matrix, [])
        
    def onecircle(self, m: List[List[int]], res: List[int]) -> List[int]:
        if len(m)==0 or (len(m)!=0 and len(m[0])==0): return res
        res += self.getcircle(m)
        m = self.deletecircle(m)
        return self.onecircle(m, res)
        
    def getcircle(self, m: List[List[int]]) -> List[int]:
        ll = len(m)
        if ll==1: return m[0]
        elif len(m[0])==1:
            res=[]
            for i in m: res.append(i[0])
        else:
            res=m[0].copy()
            res = res[:-1:]
            for i in m: res.append(i[-1])
            res = res[:-1:]
            res += m[-1][::-1].copy()
            res = res[:-1:]
            for i in range(ll-1): res.append(m[ll-1-i][0])
        return res
             
    def deletecircle(self, m:List[List[int]]) -> List[List[int]]:
        ll = len(m)
        if ll==1 or len(m[0])==1: return []
        else: 
            m = m[1:ll-1:]
            if m != []:
                for i in range(ll-2): 
                    m[i] = m[i][1::]
                    m[i] = m[i][:-1:]
        return m
```
