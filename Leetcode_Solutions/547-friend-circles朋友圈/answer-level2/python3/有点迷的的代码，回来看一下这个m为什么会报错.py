```
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        li=[]
        for i in range(len(M)-1):
            for j in range(i+1,len(M)):
                if M[i][j]==1:li.append(list([i,j]))
        print(li)
        print(li[0][1])
        res=0
        while len(li)!=0:
            res+=1
            li2=[]
            m=li[0]
            print(li[][1])
            # print(m)
            li=li[1:]
            li2.append(m[0])
            li2.append(m[1])
            se=set()
            se.add(m[0])
            se.add(m[1])
            while li2:
                k2=li2.pop(0)
                for i in range(len(li)):
                    if li[i][0]==k2: 
                        m=li.pop(i)
                        if m[1] not in se:
                            li.append(m[1])
                            se.add(m[1])
        return res
```
