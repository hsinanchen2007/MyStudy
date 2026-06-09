### 解题思路
读懂题目很重要呢

### 代码

```python

## 最后计算，checkin checkout仅仅记录
class UndergroundSystem(object):

    def __init__(self):
        self.S_sta_id_t = dict()
        self.E_sta_id_t = dict()


    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        if stationName not in self.S_sta_id_t:
            self.S_sta_id_t[stationName] = dict()
        self.S_sta_id_t[stationName][id] = t 


    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        if stationName not in self.E_sta_id_t:
            self.E_sta_id_t[stationName] = dict()
        self.E_sta_id_t[stationName][id] = t 


    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        S_id_t = self.S_sta_id_t[startStation]
        E_id_t = self.E_sta_id_t[endStation]
        res = 0.0
        count = 0
        for id, t in E_id_t.items():
            st = S_id_t.get(id, None) ## 有非法的
            if st is None:
                continue
            res += (t - st)
            count += 1
        if count == 0:
            return 0.0 
        return res / count 


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
```

代码二： 仍然存在错误case，但却没有找打原因 
    - 最终查明是python2 无法通过
    - python2.X 需要：return sum_*1.0 / count 
```
## checkout 计算，getAverageTime读取
class UndergroundSystem(object):

    def __init__(self):
        self.id_st = dict()
        self.se_cs = dict()


    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self.id_st[id] = (stationName, t)



    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        start, st = self.id_st.get(id, (None, 0))
        if start is None:
            return 
        count, sum_ = self.se_cs.get((start, stationName), (0, 0))
        self.se_cs[(start, stationName)] = (count+1, sum_+t-st)


    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        count, sum_ =  self.se_cs.get((startStation, endStation), (0, 0))
        if count == 0:
            return 0.0
        return sum_ / count 

```
class UndergroundSystem:
    ## checkout 计算，getAverageTime读取
    def __init__(self):
        self.id_st = dict() ## key:id, val: (startName, startTime)
        self.se_cs = dict() ## key: (startStation, endStation) val: count, all_time

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        
        self.id_st[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        start, st = self.id_st.get(id, (None, 0))
        if start is None:
            return 
        idx = (start, stationName)
        count, sum_ = self.se_cs.get(idx, (0, 0))
        self.se_cs[idx] = (count+1, sum_+t-st)


    def getAverageTime(self, startStation: str, endStation: str) -> float:
        idx = (startStation, endStation)
        count, sum_ =  self.se_cs.get(idx, (0, 0))
        if count == 0:
            return 0.0
        return sum_ / count 
