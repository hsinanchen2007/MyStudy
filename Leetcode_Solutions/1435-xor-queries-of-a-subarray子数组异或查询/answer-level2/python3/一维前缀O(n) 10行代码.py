class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        res=[]
        d=[]
        d.append(arr[0])
        for i in range(1,len(arr)):
            d.append(d[-1]^arr[i])
        for q in queries:
            if q[0]>0:
                res.append(d[q[1]]^d[q[0]-1])
            else:
                res.append(d[q[1]])
        return res