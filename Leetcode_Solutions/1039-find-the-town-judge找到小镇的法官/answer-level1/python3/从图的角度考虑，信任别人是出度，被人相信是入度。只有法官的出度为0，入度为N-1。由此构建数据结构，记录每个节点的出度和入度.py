```
class Solution:
    def findJudge(self, N: int, trust):
        dict={ i:[0,0] for i in range(1,N+1)} #dict记录每个节点的出度和入度
        for i in trust :
            dict[i[0]][0]+=1
            dict[i[1]][1]+=1
        for i,j in dict.items() :
            if j[0]==0 and j[1]==N-1 :
                return i
        return -1
```
