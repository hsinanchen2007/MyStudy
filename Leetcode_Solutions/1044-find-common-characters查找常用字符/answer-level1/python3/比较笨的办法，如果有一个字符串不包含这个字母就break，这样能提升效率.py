from collections import Counter
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        res=[]
        if not A: return []
        A=sorted(A,key=lambda x:len(x))
        tmp=Counter(A[0])
        for j in tmp:
            count=tmp.get(j)
            for i in range(1,len(A),1):         
                count=min(count,A[i].count(j))
                if count==0:
                    break
            for a in range(count):
                res.append(j)
        return res


