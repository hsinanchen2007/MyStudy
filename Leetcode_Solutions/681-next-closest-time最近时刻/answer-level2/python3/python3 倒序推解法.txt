1. 如果最后一位不是最大，那就换成比它大的数中最小的一个
2. 如果最后一位是最大
    2.1 把最后一位换成最小
    2.2 然后倒序往前，换成比它大的数中最小的一个，如果不存在或者不符合条件，就换成最小值
```

class Solution:
    def nextClosestTime(self, time: str) -> str:
        times = []
        for c in time:
            if c!=":": 
                times.append(int(c))
        sortedTime = list(sorted(set(times)))
        maxTime1 = [2,3,5,9]
        if times[-1]!=sortedTime[-1]:
            times[-1] = sortedTime[sortedTime.index(times[-1])+1]
            return str(times[0])+str(times[1])+":"+str(times[2])+str(times[3])
        else:
            times[-1] = sortedTime[0]
            for i in range(len(times)-2,0,-1):
                if sortedTime.index(times[i]) == len(sortedTime)-1:
                    times[i] = sortedTime[0]
                else:
                    larger = sortedTime[sortedTime.index(times[i])+1]
                    if i >1:
                        if larger>maxTime1[i]:
                            times[i] = sortedTime[0]
                        else:
                            times[i] = larger
                            return str(times[0])+str(times[1])+":"+str(times[2])+str(times[3])
                    else:
                        if times[0]*10+larger>23:
                            times[i] = sortedTime[0]
                        else:
                            times[i] = larger
                            return str(times[0])+str(times[1])+":"+str(times[2])+str(times[3])
        return str(times[0])+str(times[1])+":"+str(times[2])+str(times[3])
```
