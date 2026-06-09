```
class UndergroundSystem:

    def __init__(self):
        from collections import defaultdict
        self.checkInTime=defaultdict(list)
        self.intervals=defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        #记录上车信心{ID：[上车时间，上车站台]}
        self.checkInTime[id]=[t,stationName]
        # print(self.checkInTime)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        #弹出下车乘客
        cur = self.checkInTime.pop(id)
        #记录上、下车的区间及乘车时间总和、总次数
        if cur[1] not in self.intervals:
            self.intervals[cur[1]]=[[stationName,t-cur[0],1]]
        else:
            flag=True
            for item in self.intervals[cur[1]]:
                if item[0]==stationName:
                    item[1]+=(t-cur[0])
                    item[2]+=1
                    flag=False
            if flag:self.intervals[cur[1]].append([stationName,t-cur[0],1])
        # print(self.intervals)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        # 找到对应上、下车区间，返回总时间/总次数
        v=self.intervals[startStation]
        for c in v:
            if c[0]==endStation:
                return c[1]/c[2]
        return -1



# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
```
