想清楚要遍历的数列长度不会超过目标值X2的开方值就行了..时间复杂度直接下降到log数量级..

附上代码
```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        re=[]
        for i in range(int((target*2)**0.5),1,-1):
            st=target/i+0.5-i/2
            if st-int(st)<0.0000001:
                ha=[]
                for i in range(i):
                    ha.append(int(st)+i)
                if sum(ha)==target and 0 not in ha:
                    re.append(ha)
        return re
```

