### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import namedtuple


class UndergroundSystem:

    def __init__(self):
        self.passengerIn = set()
        self.passengerOut = set()
        self.PassengerMessage = namedtuple('PassengerMessage', ['id', 'stationName', 't'])

    def checkIn(self, id, stationName, t):
        passenger = self.PassengerMessage(id=id, stationName=stationName, t=t)
        self.passengerIn.add(passenger)

    def checkOut(self, id, stationName, t):
        passenger = self.PassengerMessage(id=id, stationName=stationName, t=t)
        self.passengerOut.add(passenger)

    def getAverageTime(self, startStation, endStation):
        passengerIn = set()
        passengerOut = set()
        res = list()
        for i in self.passengerIn:
            if i.stationName == startStation:
                passengerIn.add(i)
        for j in self.passengerOut:
            if j.stationName == endStation:
                passengerOut.add(j)
        for a in passengerIn:
            for b in passengerOut:
                if a.id == b.id:
                    res.append(b.t - a.t)
        return sum(res) / len(res)
```
时间复杂度：O(n^2)
空间复杂度：O(n)