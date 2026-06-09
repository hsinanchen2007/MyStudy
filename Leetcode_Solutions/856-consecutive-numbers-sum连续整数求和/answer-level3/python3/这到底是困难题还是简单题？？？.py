这个hard题在在新的面试题里竟然被标记为简单
```
class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        hey=0
        for i in range(int((N*2)**0.5),1,-1):
            st=N/i+0.5-i/2
            if st-int(st)<0.0000001:
                ha=[]
                for i in range(i):
                    ha.append(int(st)+i)
                if sum(ha)==N and 0 not in ha:
                    hey+=1
        return hey+1
```
