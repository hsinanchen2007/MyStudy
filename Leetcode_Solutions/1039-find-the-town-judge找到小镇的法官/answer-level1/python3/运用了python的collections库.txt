class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        import collections
        if len(trust)==0:
            return 1
        a=[]
        b=[]
        for u in trust:
            a.append(u[0])
            b.append(u[1])
        m=collections.Counter(b)
        x,y=m.most_common(1)[0][0],m.most_common(1)[0][1]
        if x in a:
            return -1
        else:
            if y==N-1:
                return x
            else:
                return -1