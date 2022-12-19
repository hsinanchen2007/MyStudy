### 解题思路
字典存储到站和离站乘客
字典key为站台名，value为二维列表，列表值为`[id, t]`


### 代码

```python3
class UndergroundSystem:

    def __init__(self):
        self.enterstation = {}
        self.leavestation = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        if stationName not in self.enterstation:
            self.enterstation[stationName] = [[id, t]]
        else:
            self.enterstation[stationName].append([id, t])

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        if stationName not in self.leavestation:
            self.leavestation[stationName] = [[id, t]]
        else:
            self.leavestation[stationName].append([id, t])       

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        ans = []
        start = self.enterstation[startStation]
        end = self.leavestation[endStation]
        for i in start:
            for j in end:
                if i[0] == j[0]:
                    ans.append(abs(j[1] - i[1]))
        return float(sum(ans)/len(ans))



# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
```