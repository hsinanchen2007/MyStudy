```
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dic={'b':1,'a':1,'l':2,'o':2,'n':1}
        for i in text:
            if dic.get(i):
                dic[i]+=1
        
        for key in dic.keys():
            if key=='l' or key=='o':
                dic[key]=(dic[key]-2)//2
            else:
                dic[key]-=1
        
        m=10000
        for key in dic.keys():
            if dic[key]<m:
                m=dic[key]
        return m
```
