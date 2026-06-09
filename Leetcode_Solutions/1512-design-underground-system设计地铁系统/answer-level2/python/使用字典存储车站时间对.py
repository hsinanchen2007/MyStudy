```
import collections
from numpy import *
class UndergroundSystem(object):
    def __init__(self):
        self.res=collections.defaultdict(list)
        self.name=collections.defaultdict(list)


    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.name[id].append([stationName,t])
        


    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.name[id].append([stationName,t])
        self.res[(self.name[id][0][0],self.name[id][1][0])].append((self.name[id][1][1]-self.name[id][0][1]))
        self.name[id]=[]


    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        res=mean(self.res[(startStation, endStation)])
        return res
```
注意下车之后要把相应id清空！！！罚时真的一把辛酸泪