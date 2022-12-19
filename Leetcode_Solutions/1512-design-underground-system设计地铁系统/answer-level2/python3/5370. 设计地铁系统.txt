### 解题思路
这题花了我很多时间，第一次遇到这类设计题真得很懵逼。下面的代码中基本就是要算什么，就设什么样的数据结构，由于题目保证了出站一定在入站后，所以checkOut的时候，可以简单地去计算一段旅程的时间差。

### 代码

```python3
class UndergroundSystem:

    def __init__(self):
        self.IDs = collections.defaultdict(list)  #记录id的(stationName,t)
        self.travel = collections.defaultdict(list)  #记录(startStation,endStation)所用时间delta_t

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.IDs[id].append((stationName,t))  #进站登记

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        # 算出delta_t
        delta_t = t - self.IDs[id][-1][1]
        print(delta_t)
        self.travel[(self.IDs[id][-1][0],stationName)].append(delta_t)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return sum(self.travel[(startStation,endStation)])/len(self.travel[(startStation,endStation)])
```