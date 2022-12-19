### 解题思路
Use hash maps to store:
* average travel time from start to end
    * Use start station as key, and the value to this key is another hash table, which uses end station as key. They value is a list of current average time, and how many trips traveled.
* travel log for each id

For each check-in, update or create the log for this id. For each check-out, update the average time as follows:
* if the start station is new, we simply create its value per above
* if we have seen the start station, update the average time by dividing the total travel time with total trip number

### 代码

```python
class UndergroundSystem:
    def __init__(self):
        self.avg_time = {}
        self.log = {}        

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.log[id] = [stationName, t]        

    def checkOut(self, id: int, end: str, t: int) -> None:
        start, stime = self.log[id]
        if start not in self.avg_time:
            self.avg_time[start] = {end: [t - stime, 1]}
        else:
            avg, n = self.avg_time[start].get(end, [0, 0])
            self.avg_time[start][end] = [(avg*n + t - stime)/(n+1), n+1]
            
    def getAverageTime(self, start: str, end: str) -> float:
        return self.avg_time[start][end][0]
```