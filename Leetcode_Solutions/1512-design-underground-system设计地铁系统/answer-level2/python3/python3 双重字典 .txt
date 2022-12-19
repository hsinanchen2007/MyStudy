字典time记录始发站和每个id进站时间
双重字典station的key0为始发站
key1为终点站
key1的value为1×2的数组 
第一个位置存耗时 第二个位置存始发站到终点站成对出现的次数
```
class UndergroundSystem:

    def __init__(self):
        self.time = {}
        self.station = {}
        
    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.time[id] = [stationName,t]
        if stationName not in self.station:
            self.station[stationName] = {}

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        time = t-self.time[id][1]
        start = self.time[id][0]
        end = stationName
        self.station[start][end] = self.station[start].get(end,[0,0])
        self.station[start][end][0]+=time
        self.station[start][end][1]+=1
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return self.station[startStation][endStation][0]/self.station[startStation][endStation][1]
```
